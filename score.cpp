#include "score.h"
using std::ifstream;
using std::ofstream;
using std::cout;
using std::to_string;
score::score()
{
    currentSteps = 0;
    currentTime = 0;
    bestSteps = 0;
    bestTime = 0;
    scoreFont = NULL;
    textColor = { 0, 0, 0 };
}
void score::loadBestScore (string path)
{
    ifstream fi (path.c_str());
    fi >> bestSteps >> bestTime;
}

void score::loadTTFScore(SDL_Renderer* renderer)
{

    if( scoreFont == NULL )
    {
        cout << " Failed to load score scoreFont, Error: " << TTF_GetError() << '\n';
    }
    if( !cStep.loadFromRenderedText(renderer, scoreFont, "Steps: " + to_string(currentSteps) + " ", textColor ) )
    {
        cout << "Failed to load step texture, Error: " << TTF_GetError() << '\n';
    }
    if( !bStep.loadFromRenderedText(renderer, scoreFont, "Best steps: " + to_string(bestSteps) + " ", textColor ) )
    {
        cout << "Failed to load best step texture, Error: " << TTF_GetError() << '\n';
    }
    if( !cTime.loadFromRenderedText(renderer, scoreFont, "Time: " + to_string(currentTime) + " ", textColor ) )
    {
        cout << "Failed to load current time texture, Error: " << TTF_GetError() << '\n';
    }
    if( !bTime.loadFromRenderedText(renderer, scoreFont, "Best time: " + to_string(bestTime) + " ", textColor ) )
    {
        cout << "Failed to load best time texture, Error: " << TTF_GetError() << '\n';
    }
}

void score::renderScore(SDL_Renderer* renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
    cStep.render (renderer, 0, SCREEN_HEIGHT - cStep.getHeight());
    cTime.render (renderer, cStep.getWidth(), SCREEN_HEIGHT - cTime.getHeight());
    bStep.render (renderer, cStep.getWidth() + cTime.getWidth(), SCREEN_HEIGHT - bStep.getHeight());
    bTime.render (renderer, cStep.getWidth() + cTime.getWidth() + bStep.getWidth(), SCREEN_HEIGHT - bTime.getHeight());
}
void score::saveScore(string path)
{
    ofstream fo (path.c_str());
    fo << bestSteps << " " << bestTime;
}


