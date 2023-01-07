#include "game_flappy_bird.h"
#include "watch_display_util.h"

int game_state = 0;

int score = 0;
int high_score = 0;

const int bird_x = (int) display.width() / 4;
int bird_y;

int momentum = 0;

int wall_x[2];
int wall_y[2];

int wall_gap = 30;
int wall_width = 10;


void gameFlappyBird() {
  if (game_state == 0) {
    // in game
    display.clearDisplay();

    // If the flap button is currently pressed, reduce the downward force on the bird a bit.
    // Once this foce goes negative the bird goes up, otherwise it falls towards the ground
    // gaining speed
    if (digitalRead(FLAP_BUTTON) == LOW) {
      momentum = -4;
    }

    // increase the downward force on the bird
    momentum += 1;

    // add the downward force to the bird position to determine it's new position
    bird_y += momentum;

    // make sure the bird doesn't fly off the top of the screen
    if (bird_y < 0 ) {
      bird_y = 0;
    }

    // make sure the bird doesn't fall off the bottom of the screen
    // give it a slight positive lift so it 'waddles' along the ground.
    if (bird_y > display.height() - SPRITE_HEIGHT) {
      bird_y = display.height() - SPRITE_HEIGHT;
      momentum = -2;
    }

    // display the bird
    // if the momentum on the bird is negative the bird is going up!
    if (momentum < 0) {

      // display the bird using a randomly picked flap animation frame
      if (random(2) == 0) {
        display.drawBitmap(bird_x, bird_y, wing_down_bmp, 16, 16, WHITE);
      }
      else {
        display.drawBitmap(bird_x, bird_y, wing_up_bmp, 16, 16, WHITE);
      }

    }
    else {

      // bird is currently falling, use wing up frame
      display.drawBitmap(bird_x, bird_y, wing_up_bmp, 16, 16, WHITE);

    }

    // now we draw the walls and see if the player has hit anything
    for (int i = 0 ; i < 2; i++) {
      // if the wall has hit the edge of the screen
      // reset it back to the other side with a new gap position
      if (wall_x[i] < 0) {
        wall_y[i] = random(0, display.height() - wall_gap);
        wall_x[i] = display.width();
      }

      // draw the top half of the wall
      display.fillRect(wall_x[i], 0, wall_width, wall_y[i], WHITE);

      // draw the bottom half of the wall
      display.fillRect(wall_x[i], wall_y[i] + wall_gap, wall_width, display.height() - wall_y[i] + wall_gap, WHITE);

      // if the bird has passed the wall, update the score
      if (wall_x[i] == bird_x) {
        score++;

        // highscore is whichever is bigger, the current high score or the current score
        high_score = max(score, high_score);
      }

      // if the bird is level with the wall and not level with the gap - game over!
      if (
        (bird_x + SPRITE_WIDTH > wall_x[i] && bird_x < wall_x[i] + wall_width) // level with wall
        &&
        (bird_y < wall_y[i] || bird_y + SPRITE_HEIGHT > wall_y[i] + wall_gap) // not level with the gap
      ) {
        
        // display the crash and pause 1/2 a second
        display.display();
        delay(500);

        // switch to game over state
        game_state = 1; 

      }

      // move the wall left 4 pixels
      wall_x[i] -= 4;
    }

    // display the current score
    boldTextAtCenter(0, (String)score, 1);

    // now display everything to the user and wait a bit to keep things playable
    display.display();
    delay(GAME_SPEED);

  }
  else {

    // game over screen

    // screenWipe(10);

    display.clearDisplay();
    outlineTextAtCenter(1, "NANO BIRD", 1);
    
    textAtCenter(display.height() / 2 - 8, "GAME OVER", 1);
    textAtCenter(display.height() / 2, String(score), 1);
    
    boldTextAtCenter(display.height() - 16, "HIGH SCORE", 1);
    boldTextAtCenter(display.height()  - 8, String(high_score), 1);

    display.display();

    // wait while the user stops pressing the button
    // while (digitalRead(FLAP_BUTTON) == LOW);

    if (digitalRead(FLAP_BUTTON) == LOW) {
      // setup a new game
      bird_y = display.height() / 2;
      momentum = -4;
      wall_x[0] = display.width() ;
      wall_y[0] = display.height() / 2 - wall_gap / 2;
      wall_x[1] = display.width() + display.width() / 2;
      wall_y[1] = display.height() / 2 - wall_gap / 1;
      score = 0;
      // start a new game
      screenWipe(10);
      game_state = 0;
    }
    

    // wait until the user presses the button
    // while (digitalRead(FLAP_BUTTON) == HIGH);    
    
  }
}
