#include <iostream>
#include <regex>
#include "ScriptHookRDR2/inc/sdk.h"
#include "LuaBridge/LuaBridge.h"

using namespace std;
using namespace rdr2;

const std::string animationListFile = "animations.lua";

std::vector<std::pair<std::string, std::string>> parseAnimationList(const std::string& filename) {
    std::vector<std::pair<std::string, std::string>> animations;

    // Create a Lua state object
    lua_State* L = luaL_newstate();

    // Load the Lua file
    luaL_dofile(L, filename.c_str());

    // Retrieve the table of animations from the Lua state
    luabridge::LuaRef animsTable = luabridge::getGlobal(L, "animations");

    // Iterate through the table and extract the animation names and dictionary names
    for (int i = 1; i <= animsTable.length(); i++) {
        luabridge::LuaRef anim = animsTable[i];
        std::string dictName = anim["dictionary"].cast<std::string>();
        std::string animName = anim["name"].cast<std::string>();
        animations.push_back(std::make_pair(dictName, animName));
    }

    // Clean up the Lua state object
    lua_close(L);

    return animations;
}

bool isPlayingAnimation(rd::CPed& ped, const char* animDict, const char* animName) {
    bool playing = ENTITY::IS_ENTITY_PLAYING_ANIM(ped, animDict, animName, 3);
    if (!playing) {
        playing = TASK::IS_PED_ACTIVE_IN_SCENARIO(ped, animDict, animName);
    }
    return playing;
}

void MainLoop() {
    std::vector<std::pair<std::string, std::string>> animations = parseAnimationList(animationListFile);

    while (true) {
        script::Wait(0);

        if (script::IsKeyJustUp(VK_F5)) {
            rd::CPed playerPed = PLAYER::PLAYER_PED_ID();

            for (const auto& anim : animations) {
                if (isPlayingAnimation(playerPed, anim.first.c_str(), anim.second.c_str())) {
                    std::string animationInfo = anim.first + ", " + anim.second;
                    UI::PRINT_HELP("Animation copied to clipboard: " + animationInfo);
                    break;
                }
            }
        }
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        script::scriptRegister(hModule, MainLoop);
    }
    else if (ul_reason_for_call == DLL_PROCESS_DETACH) {
        script::scriptUnregister(hModule);
    }
    return TRUE;
}
