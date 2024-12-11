#pragma once

namespace Flappy
{

// 768 * 1024
#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024
#define SPLASH_STATE_SHOW_TIME 3.0


// Resource directory
#define RES_DIR "Resources/res/"


// Fonts
#define FLAPPY_FONT_FILEPATH "Resources/fonts/FlappyFont.ttf"

#define GAME_OVER_TITLE_FILEPATH "Resources/res/Game-Over-Title.png"
#define GAME_OVER_BODY_FILEPATH "Resources/res/Game-Over-Body.png"

// backgrounds
#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/res/Splash Background.png"

#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/res/sky.png"
//#define GAME_BACKGROUND_FILEPATH "Resources/res/sky.png"
#define GAME_BACKGROUND_FILENAME "sky.png"
#define GAME_OVER_BACKGROUND_FILEPATH "Resources/res/sky.png"

#define PIPE_UP_FILEPATH "Resources/res/PipeUp.png"
#define PIPE_DOWN_FILEPATH "Resources/res/PipeDown.png"
#define PIPE_UP_FILENAME "PipeUp.png"
#define PIPE_DOWN_FILENAME "PipeDown.png"
#define GAME_TITLE_FILEPATH "Resources/res/title.png"
#define PLAY_BUTTON_FILEPATH "Resources/res/PlayButton.png"
#define SCORING_PIPE_FILEPATH "Resources/res/InvisibleScoringPipe.png"

// Pipe Parameters
#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_SPAWN_FREQUENCY 2.2f

// land texture
#define LAND_FILENAME "Land.png"

// bird animations
#define BIRD_FRAME_1_FILENAME "bird-01.png"
#define BIRD_FRAME_2_FILENAME "bird-02.png"
#define BIRD_FRAME_3_FILENAME "bird-03.png"
#define BIRD_FRAME_4_FILENAME "bird-04.png"

#define BIRD_ANIMATION_DURATION 0.25f

#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3

#define GRAVITY 350.0f
#define FLYING_SPEED 350.0f

#define FLYING_DURATION 0.25f
#define ROTATION_SPEED 100.0f

enum GameStates
{
	eReady,
	ePlaying,
	eGameOver

};

#define FLASH_SPEED 1500.0f
#define TIME_BEFORE_GAME_APPEARS 1.5f

#define HIGH_SCORE_TEXT_FILEPATH "Resources/HighScore.txt"

#define BRONZE_MEDAL_FILEPATH "Resources/res/Bronze-Medal.png"
#define SILVER_MEDAL_FILEPATH "Resources/res/Silver-Medal.png"
#define GOLD_MEDAL_FILEPATH "Resources/res/Gold-Medal.png"
#define PLATINUM_MEDAL_FILEPATH "Resources/res/Platinum-Medal.png"

#define BRONZE_MEDAL_SCORE 0
#define SILVER_MEDAL_SCORE 50
#define GOLD_MEDAL_SCORE 100
#define PLATINUM_MEDAL_SCORE 150


#define HIT_SOUND_FILEPATH "Resources/audio/Hit.wav"
#define POINT_SOUND_FILEPATH "Resources/audio/Point.wav"
#define WING_SOUND_FILEPATH "Resources/audio/Wing.wav"















}