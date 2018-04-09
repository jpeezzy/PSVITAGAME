cmake_minimum_required(VERSION 2.8)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()

set(SHORT_NAME spritetest)
project(${SHORT_NAME})
include("${VITASDK}/share/vita.cmake" REQUIRED)

set(VITA_APP_NAME "Sprite Test")
#set(VITA_TITLEID  "VSDK00013")
set(VITA_TITLEID  "0N1YS3V3N")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(
	../../common #For debugscreenprintf
)

#add additional ibraries path here
link_directories(
	${CMAKE_CURRENT_BINARY_DIR}
)

add_executable(${SHORT_NAME}
  src/main.cpp
  src/grid.cpp
)

target_link_libraries(${SHORT_NAME}
  SDL2
  SDL2_mixer
  SDL2_image
  jpeg
  png
  z
  vita2d
  SceDisplay_stub
  SceCtrl_stub
  SceAudio_stub
  SceSysmodule_stub
  SceGxm_stub
  SceCommonDialog_stub
  SceTouch_stub
  SceHid_stub
  SceLibKernel_stub
  m
)
#Creating VPK
vita_create_self(${SHORT_NAME}.self ${SHORT_NAME})
vita_create_vpk(${SHORT_NAME}.vpk ${VITA_TITLEID} ${SHORT_NAME}.self
  VERSION ${VITA_VERSION}
  NAME ${VITA_APP_NAME}
  FILE sce_sys/icon0.png sce_sys/icon0.png
  FILE sce_sys/livearea/contents/bg.png sce_sys/livearea/contents/bg.png
  FILE sce_sys/livearea/contents/startup.png sce_sys/livearea/contents/startup.png
  FILE sce_sys/livearea/contents/template.xml sce_sys/livearea/contents/template.xml
  #GameImages 
  FILE sce_sys/images/alert_0.png sce_sys/images/alert_0.png
  #FILES FOR HOBBES startup
  FILE sce_sys/images/sprites/HobbesStartup/effect.0.png sce_sys/images/sprites/HobbesStartup/effect.0.png
  FILE sce_sys/images/sprites/HobbesStartup/effect.1.png sce_sys/images/sprites/HobbesStartup/effect.1.png
  FILE sce_sys/images/sprites/HobbesStartup/effect.2.png sce_sys/images/sprites/HobbesStartup/effect.2.png
  FILE sce_sys/images/sprites/HobbesStartup/effect.3.png sce_sys/images/sprites/HobbesStartup/effect.3.png
  FILE sce_sys/images/sprites/HobbesStartup/effect.4.png sce_sys/images/sprites/HobbesStartup/effect.4.png
  FILE sce_sys/images/sprites/HobbesStartup/effect.5.png sce_sys/images/sprites/HobbesStartup/effect.5.png
  FILE sce_sys/images/sprites/HobbesStartup/effect.6.png sce_sys/images/sprites/HobbesStartup/effect.6.png
  FILE sce_sys/images/sprites/HobbesStartup/effect.7.png sce_sys/images/sprites/HobbesStartup/effect.7.png
  FILE sce_sys/images/sprites/HobbesStartup/effect.8.png sce_sys/images/sprites/HobbesStartup/effect.8.png
  FILE sce_sys/images/sprites/HobbesStartup/effect.9.png sce_sys/images/sprites/HobbesStartup/effect.9.png
  FILE sce_sys/images/sprites/HobbesStartup/effect.10.png sce_sys/images/sprites/HobbesStartup/effect.10.png
  #Hobbes Sprite
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/alert_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/alert_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/alert_1.png sce_sys/images/sprites/Hobbes/blink/frame_0/alert_1.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/alert_2.png sce_sys/images/sprites/Hobbes/blink/frame_0/alert_2.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/alert_3.png sce_sys/images/sprites/Hobbes/blink/frame_0/alert_3.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/alert_4.png sce_sys/images/sprites/Hobbes/blink/frame_0/alert_4.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/fly_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/fly_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/fly_1.png sce_sys/images/sprites/Hobbes/blink/frame_0/fly_1.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/heal_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/heal_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/heal_1.png sce_sys/images/sprites/Hobbes/blink/frame_0/heal_1.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/heal_2.png sce_sys/images/sprites/Hobbes/blink/frame_0/heal_2.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/jump_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/jump_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/ladder_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/ladder_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/ladder_1.png sce_sys/images/sprites/Hobbes/blink/frame_0/ladder_1.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/proneStab_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/proneStab_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/proneStab_1.png sce_sys/images/sprites/Hobbes/blink/frame_0/proneStab_1.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/prone_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/prone_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/rope_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/rope_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/rope_1.png sce_sys/images/sprites/Hobbes/blink/frame_0/rope_1.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/shoot1_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/shoot1_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/shoot1_1.png sce_sys/images/sprites/Hobbes/blink/frame_0/shoot1_1.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/shoot1_2.png sce_sys/images/sprites/Hobbes/blink/frame_0/shoot1_2.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/shoot2_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/shoot2_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/shoot2_1.png sce_sys/images/sprites/Hobbes/blink/frame_0/shoot2_1.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/shoot2_2.png sce_sys/images/sprites/Hobbes/blink/frame_0/shoot2_2.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/shoot2_3.png sce_sys/images/sprites/Hobbes/blink/frame_0/shoot2_3.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/shoot2_4.png sce_sys/images/sprites/Hobbes/blink/frame_0/shoot2_4.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/shootF_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/shootF_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/shootF_1.png sce_sys/images/sprites/Hobbes/blink/frame_0/shootF_1.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/shootF_2.png sce_sys/images/sprites/Hobbes/blink/frame_0/shootF_2.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/sit_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/sit_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/stabO1_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/stabO1_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/stabO1_1.png sce_sys/images/sprites/Hobbes/blink/frame_0/stabO1_1.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/stabO2_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/stabO2_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/stabO2_1.png sce_sys/images/sprites/Hobbes/blink/frame_0/stabO2_1.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/stabOF_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/stabOF_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/stabOF_1.png sce_sys/images/sprites/Hobbes/blink/frame_0/stabOF_1.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/stabOF_2.png sce_sys/images/sprites/Hobbes/blink/frame_0/stabOF_2.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/stabT1_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/stabT1_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/stabT1_1.png sce_sys/images/sprites/Hobbes/blink/frame_0/stabT1_1.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/stabT1_2.png sce_sys/images/sprites/Hobbes/blink/frame_0/stabT1_2.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/stabT2_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/stabT2_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/stabT2_1.png sce_sys/images/sprites/Hobbes/blink/frame_0/stabT2_1.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/stabT2_2.png sce_sys/images/sprites/Hobbes/blink/frame_0/stabT2_2.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/stabTF_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/stabTF_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/stabTF_1.png sce_sys/images/sprites/Hobbes/blink/frame_0/stabTF_1.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/stabTF_2.png sce_sys/images/sprites/Hobbes/blink/frame_0/stabTF_2.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/stabTF_3.png sce_sys/images/sprites/Hobbes/blink/frame_0/stabTF_3.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/stand1_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/stand1_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/stand1_1.png sce_sys/images/sprites/Hobbes/blink/frame_0/stand1_1.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/stand1_2.png sce_sys/images/sprites/Hobbes/blink/frame_0/stand1_2.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/stand1_3.png sce_sys/images/sprites/Hobbes/blink/frame_0/stand1_3.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/stand1_4.png sce_sys/images/sprites/Hobbes/blink/frame_0/stand1_4.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/stand2_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/stand2_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/stand2_1.png sce_sys/images/sprites/Hobbes/blink/frame_0/stand2_1.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/stand2_2.png sce_sys/images/sprites/Hobbes/blink/frame_0/stand2_2.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/stand2_3.png sce_sys/images/sprites/Hobbes/blink/frame_0/stand2_3.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/stand2_4.png sce_sys/images/sprites/Hobbes/blink/frame_0/stand2_4.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingO1_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingO1_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingO1_1.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingO1_1.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingO1_2.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingO1_2.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingO2_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingO2_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingO2_1.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingO2_1.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingO2_2.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingO2_2.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingO3_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingO3_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingO3_1.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingO3_1.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingO3_2.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingO3_2.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingOF_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingOF_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingOF_1.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingOF_1.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingOF_2.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingOF_2.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingOF_3.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingOF_3.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingP1_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingP1_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingP1_1.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingP1_1.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingP1_2.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingP1_2.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingP2_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingP2_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingP2_1.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingP2_1.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingP2_2.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingP2_2.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingPF_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingPF_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingPF_1.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingPF_1.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingPF_2.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingPF_2.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingPF_3.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingPF_3.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingT1_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingT1_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingT1_1.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingT1_1.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingT1_2.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingT1_2.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingT2_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingT2_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingT2_1.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingT2_1.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingT2_2.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingT2_2.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingT3_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingT3_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingT3_1.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingT3_1.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingT3_2.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingT3_2.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingTF_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingTF_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingTF_1.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingTF_1.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingTF_2.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingTF_2.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/swingTF_3.png sce_sys/images/sprites/Hobbes/blink/frame_0/swingTF_3.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/walk1_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/walk1_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/walk1_1.png sce_sys/images/sprites/Hobbes/blink/frame_0/walk1_1.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/walk1_2.png sce_sys/images/sprites/Hobbes/blink/frame_0/walk1_2.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/walk1_3.png sce_sys/images/sprites/Hobbes/blink/frame_0/walk1_3.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/walk2_0.png sce_sys/images/sprites/Hobbes/blink/frame_0/walk2_0.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/walk2_1.png sce_sys/images/sprites/Hobbes/blink/frame_0/walk2_1.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/walk2_2.png sce_sys/images/sprites/Hobbes/blink/frame_0/walk2_2.png
  FILE sce_sys/images/sprites/Hobbes/blink/frame_0/walk2_3.png sce_sys/images/sprites/Hobbes/blink/frame_0/walk2_3.png
)
