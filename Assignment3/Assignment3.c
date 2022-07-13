#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int x, y, count;
  char ch;
  char name[30];
  // Interactive
  printf("Welcome to Number guessing game!!乁[ ◕ ᴥ ◕ ]ㄏ\n");
  printf("What's your name!??? : ");
  scanf("%s", name);
  printf("\n(ﾉ´∀｀)ﾉ ... Hello ... %s ヾ(´▽｀;)ゝ\n", name);
  // Loop program
  do {
    srand((unsigned int)time(NULL));
    x = rand() % 100 + 1;
    count = 0;
    // Test program
    printf("x= %d\n", x);
    // Guess game
    do {
      count++;
      printf("\nGuess round : %d\n", count);
      scanf("%d", &y);
      if (x == y) {
        printf("Yes!! Bravo! Why are you so GOD ヽ|･з･|ゞ\n");
      } else {
        if (y < x) {
          printf("Your guess is too low");
        } else {
          printf("Your guess is too high");
        }
        if (count == 7) {
          printf(
              " and you lose, but it's OK babe...\nAnswer is %d hahaha eiei\n",
              x);
        }
      }
    } while (x != y && count < 7);
    do {
      printf("Enter y to play again or n to exit.");
      scanf(" %c", &ch);
    } while (ch != 'y' && ch != 'Y' && ch != 'n');
  } while (ch == 'y' || ch == 'Y');

  return 0;
}
