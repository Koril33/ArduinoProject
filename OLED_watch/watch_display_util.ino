/**
 * clear the screen using a wipe down animation
 */
void screenWipe(int speed) {

  // progressivly fill screen with white
  for (int i = 0; i < display.height(); i += speed) {
    display.fillRect(0, i, display.width(), speed, WHITE);
    display.display();
  }

  // progressively fill the screen with black
  for (int i = 0; i < display.height(); i += speed) {
    display.fillRect(0, i, display.width(), speed, BLACK);
    display.display();
  }

}

/**
 * displays txt at x,y coordinates
 */
void textAt(int x, int y, String txt, int txt_size) {
  display.setTextSize(txt_size);
  display.setCursor(x, y);
  display.print(txt);
}

/**
 * displays text centered on the line
 */
void textAtCenter(int y, String txt, int txt_size) {
  textAt(display.width() / 2 - txt.length() * 3 * txt_size, y, txt, txt_size);
}

/**
 * displays outlined text centered on the line
 */
void outlineTextAtCenter(int y, String txt, int txt_size) {
  int x = display.width() / 2 - txt.length() * 3 * txt_size;

  display.setTextColor(WHITE);
  textAt(x - 1, y, txt, txt_size);
  textAt(x + 1, y, txt, txt_size);
  textAt(x, y - 1, txt, txt_size);
  textAt(x, y + 1, txt, txt_size);

  display.setTextColor(BLACK);
  textAt(x, y, txt, txt_size);
  display.setTextColor(WHITE);

}

/**
 * displays bold text centered on the line
 */
void boldTextAtCenter(int y, String txt, int txt_size) {
  int x = display.width() / 2 - txt.length() * 3;

  textAt(x, y, txt, txt_size);
  textAt(x + 1, y, txt, txt_size);

}
