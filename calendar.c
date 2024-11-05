#include <stdio.h>

int checkForLeapYear(int year)
{
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
  {
    printf("\nThis year is a leap year.\n");
    return 1;
  }

  printf("\nThis year is not a leap year.\n");
  return 0;
}

/**
 * This function uses Zeller's Congruence to calculate the first day of the week for a given year.
 */
int firstDayOfYear(int year)
{
  const int MONTH = 13;               // If before March (3), take number of month and add 12 (Jan = 1 + 12)
  const int YEAR_ADJUSTED = year - 1; // If Jan or Feb, must adjust year by -1
  const int K = YEAR_ADJUSTED % 100;
  const int J = YEAR_ADJUSTED / 100;
  const int DAY = 1;

  // Here is the actual formula
  int f = DAY + ((13 * (MONTH + 1)) / 5) + K + (K / 4) + (J / 4) - (2 * J);
  int dayOfTheWeek = f % 7;

  const char *DAYS[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
  printf("\nThe first day of the week of the year %d was or will be a %s.\n", year, DAYS[dayOfTheWeek]);

  // return something, even if unused
  return dayOfTheWeek;
}

int main()
{
  const char *MONTHS[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  const char *DAYS_OF_WEEK_ABV[] = {"Sat", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri"};
  const int DAYS_IN_MONTHS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int year;

  printf("There are %d days in %s\n\n", DAYS_IN_MONTHS[0], MONTHS[0]);

  printf("Please enter a year: ");
  scanf(" %d", &year);

  checkForLeapYear(year);
  firstDayOfYear(year);

  return 0;
}