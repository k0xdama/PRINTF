#include <stdio.h>

int	main(void)
{
	// printf("SOME MIX\n");
	// printf("%c - %s - %p %d - %i - %u - %x %X %%", 'a', "test", (void *)0xdeadc0de, 20, -20, -1, -1, 200000000);
	// printf("char and width\n");
	// printf("%10c", 'a');
	// printf("\n");
	// printf("%010d", 42);
	// printf("\n");
	// printf("%10c", '\0'); //cat -e
	// printf("\n");
	// printf("%2c", 'c');
	// printf("\n");
	// printf("there are 15 spaces between this text and the next char%15c", 'd');
	// printf("\n");
	// printf("%5chis paragraph is indented", 't');
	// printf("\n");

	// printf("STRING WITH WIDTH\n");
	// printf("%1s", "abc");
	// printf("\n");
	// printf("%7s", "abc");
	// printf("\n");
	// char *str = NULL;
	// printf("%5s", str);
	// printf("\n");
	// printf("%7s", str);
	// printf("\n");
	// printf("%13s are the three first letter of the %3s", "a, b and c", "alphabet");
	// printf("\n");
	// printf("%s%13s%42s%3s", "a, b and c", " are letters", " of the", " alphabet");
	// printf("\n");
	// printf("%sc%13sd%42sp%3sx", "a, b and c", " are letters", " of the", " alphabet");
	// printf("\n");

	// printf("POINTERS WITH WIDTH");
	// printf("\n");
	// char c = 'a';
	// printf("%30p", &c);
	// printf("\n");
	// printf("the address is %13p", (void *)0x7ffe6b8e60c8);
	// printf("\n");
	// printf("the address is %3p", (void *)0);
	// printf("\n");
	// printf("the address is %8p", (void *)0);
	// printf("\n");
	// printf("%13p is the address", (void *)0x7ffe6b8e60c8);
	// printf("\n");
	// printf("%3p is the address", (void *)0);
	// printf("\n");
	// printf("%8p is the address", (void *)0);
	// printf("\n");

	// printf("INT WITH WIDTH");
	// printf("\n");
	// printf("%1d", 0);
	// printf("\n");
	// printf("%42d", 42000);
	// printf("\n");
	// printf("%20d", -42000);
	// printf("\n");
	// printf("wait for it... %50d", 42);
	// printf("\n");
	// printf("%30d", 2147483647);
	// printf("\n");
	// printf("%30d", (int)-2147483648);
	// printf("\n");
	// printf("%11d", (int)-2147483648);
	// printf("\n");
	// printf("%12d, %d, %2d, %42d", (int)-2147483648, 3, 30, -1);
	// printf("\n");
	// printf("%14dc%20ds%2dx%du", (int)-2147483648, 3, 30, -1);
	// printf("\n");

	// printf("%%I WITH WIDTH");
	// printf("\n");
	// printf("%1i", 0);
	// printf("\n");
	// printf("%42i", 42000);
	// printf("\n");
	// printf("%20i", -42000);
	// printf("\n");
	// printf("wait for it... %50i", 42);
	// printf("\n");
	// printf("%30i", 2147483647);
	// printf("\n");
	// printf("%30i", (int)-2147483648);
	// printf("\n");
	// printf("%11i", (int)-2147483648);
	// printf("\n");
	// printf("%12i, %i, %2i, %42i", (int)-2147483648, 3, 30, -1);
	// printf("\n");
	// printf("%14ic%20is%2ix%iu", (int)-2147483648, 3, 30, -1);
	// printf("\n");

	// printf("UNSIGNED WITH WIDTH");
	// printf("\n");
	// printf("%1u", 0);
	// printf("\n");
	// printf("%30u", 1000);
	// printf("\n");
	// printf("%11uis the biggest unsigned int", (unsigned int)-1);
	// printf("\n");
	// printf("the biggest unsigned int is %11u", (unsigned int)-1);
	// printf("\n");
	// printf("Here are some numbers: %1u%2u%5u%3u%9u and %ui", 11, (unsigned int)-1, 2, 200, 3, 10);
	// printf("\n");

	// printf("HEXA MIN AND MAJ WITH WIDTH");
	// printf("\n");
	// printf("%1x", 0);
	// printf("\n");
	// printf("%1X", 0);
	// printf("\n");
	// printf("%3x", 10);
	// printf("\n");
	// printf("%3X", 10);
	// printf("\n");
	// printf("%3x", 255);
	// printf("\n");
	// printf("%3X", 255);
	// printf("\n");
	// printf("%9x", (unsigned int)3735929054);
	// printf("\n");
	// printf("%9X", (unsigned int)3735929054);
	// printf("\n");
	// printf("the password is %9x", (unsigned int)3735929054);
	// printf("\n");
	// printf("the password is %9X", (unsigned int)3735929054);
	// printf("\n");
	// printf("%3x is the definitive answer", (unsigned int)66);
	// printf("\n");
	// printf("%3X is the definitive answer", (unsigned int)66);
	// printf("\n");
	// printf("this is the real number: %9x", (unsigned int)-1);
	// printf("\n");
	// printf("this is the real number: %9X", (unsigned int)-1);
	// printf("\n");
	// printf("%1x%2x%9x", (unsigned int)-1, 0xf0ca, 123456);
	// printf("\n");
	// printf("%1X%2X%9X", (unsigned int)-1, 0xf0ca, 123456);
	// printf("\n");
	// printf("%1xis doomed%2xpost%9xX args", (unsigned int)-1, 0xf0b1a, 7654321);
	// printf("\n");
	// printf("%1Xis doomed%2Xpost%9Xx args", (unsigned int)-1, 0xf0b1a, 7654321);

	// printf("STRING WITH PRECISION");
	// printf("\n");
	// printf("%.s", "hi there");
	// printf("\n");
	// printf("%.0s", "hi there");
	// printf("\n");
	// printf("%.1s", "hi there");
	// printf("\n");
	// printf("%.2s", "hi there");
	// printf("\n");
	// printf("%.3s", "hi there");
	// printf("\n");
	// printf("%.12s", "hi there");
	// printf("\n");
	// printf("%.s", "-42");
	// printf("\n");
	// printf("%.0s", "-42");
	// printf("\n");
	// printf("%.2s", "-42");
	// printf("\n");
	// printf("%.4s", "-42");
	// printf("\n");
	// char *str1 = NULL;
	// printf("%.2s", str1);
	// printf("\n");
	// printf("%.7s", str1);
	// printf("\n");
	// printf("This %.3s a triumph ", "wasabi");
	// printf("\n");
	// printf("%.11s%.6s%.4s", "Aperture", " Scientists", "ce");
	// printf("\n");
	// printf("%1.s", "21-school.ru");
	// printf("\n");
	// printf("%10.1s", "21-school.ru");
	// printf("\n");

	// printf("%%d AND %%i WITH PRECISION");
	// printf("\n");
	// printf("%.1d", 2);
	// printf("\n");
	// printf("%.1i", 2);
	// printf("\n");
	// printf("%.4d", 32);
	// printf("\n");
	// printf("%.4i", 32);
	// printf("\n");
	// printf("%.3d", -1);
	// printf("\n");
	// printf("%.3i", -1);
	// printf("\n");
	// printf("%.5d", -1234);
	// printf("\n");
	// printf("%.5i", -1234);
	// printf("\n");
	// printf("%.9d", (int)-2147483648);
	// printf("\n");
	// printf("%.9i", (int)-2147483648);
	// printf("\n");
	// printf("%.12d", (int)-2147483648);
	// printf("\n");
	// printf("%.12i", (int)-2147483648);
	// printf("\n");
	// printf("%.9d", 2147483647);
	// printf("\n");
	// printf("%.9i", 2147483647);
	// printf("\n");
	// printf("%.12d", 2147483647);
	// printf("\n");
	// printf("%.12d", 2147483647);
	// printf("\n");
	// printf("%.0d", 2147483647);
	// printf("\n");
	// printf("%.0i", 2147483647);
	// printf("\n");
	// printf("%.0d", 10);
	// printf("\n");
	// printf("%.0i", 10);
	// printf("\n");
	// printf("%.d", 0);
	// printf("\n");
	// printf("%.i", 0);
	// printf("\n");
	// printf("%.3d is the movie I'm gonna watch", 7);
	// printf("\n");
	// printf("%.3i is the movie I'm gonna watch", 7);
	// printf("\n");
	// printf("Then take these %.7d things and get the hell out of here", 2);
	// printf("\n");
	// printf("Then take these %.7i things and get the hell out of here", 2);
	// printf("\n");
	// printf("Bla %.2di bla %.5dsbla bla %.dx bla %.d", 127, 42, 1023, 0);
	// printf("\n");
	// printf("Bla %.2ii bla %.5isbla bla %.ix bla %.i", 127, 42, 1023, 0);
	// printf("\n");
	// printf("%.4d%.2d%.20d%.0d%.0d%.d%.d%.d", 127, 0, 1023, 0, (int)-2147483648, 0, 1, (int)-2147483648);
	// printf("\n");
	// printf("%.4i%.2i%.20i%.0i%.0i%.i%.i%.i", 127, 0, 1023, 0, (int)-2147483648, 0, 1, (int)-2147483648);
	// printf("\n");

	// printf("UNSIGNED WITH PRECISION");
	// printf("\n");
	// printf("%.1u", 1);
	// printf("\n");
	// printf("%.2u", 1);
	// printf("\n");
	// printf("%.2u", 0);
	// printf("\n");
	// printf("%.0u", 0);
	// printf("\n");
	// printf("%.u", 0);
	// printf("\n");
	// printf("%.2u", 30000);
	// printf("\n");
	// printf("%.20u", 30000);
	// printf("\n");
	// printf("%.0u", (unsigned int)-1);
	// printf("\n");
	// printf("%.5u", (unsigned int)-1);
	// printf("\n");
	// printf("%.10u", (unsigned int)-1);
	// printf("\n");
	// printf("%.11u", (unsigned int)-1);
	// printf("\n");
	// printf("%.0uis a big number", (unsigned int)-1);
	// printf("\n");
	// printf("%.4us a big number", (unsigned int)-1);
	// printf("\n");
	// printf("%.9uxs a big number", (unsigned int)-1);
	// printf("\n");
	// printf("%.11ups a big number", (unsigned int)-1);
	// printf("\n");
	// printf("the number is %.5u", (unsigned int)-1);
	// printf("\n");
	// printf("the number is %.10u", (unsigned int)-1);
	// printf("\n");
	// printf("the number is %.11u", (unsigned int)-1);
	// printf("\n");
	// printf("%.4us a big number", 0);
	// printf("\n");
	// printf("the number is %.5u", 0);
	// printf("\n");
	// printf("%u%.5u%.0u%.u%.9u", 5, 55, 2, 0, 42);
	// printf("\n");
	// printf("%us%.5ui%.0uc%.up%.9ux", 5, 55, 2, 0, 42);
	// printf("\n");

	// printf("HEXA MAJ AND MIN WITH PRECISION");
	// printf("\n");
	// printf("%.1x", 0xa);
	// printf("\n");
	// printf("%.1X", 0xa);
	// printf("\n");
	// printf("%.4x", 11);
	// printf("\n");
	// printf("%.4X", 11);
	// printf("\n");
	// printf("%.14x", -1);
	// printf("\n");
	// printf("%.14X", -1);
	// printf("\n");
	// printf("%.10x", (unsigned int)-1);
	// printf("\n");
	// printf("%.10X", (unsigned int)-1);
	// printf("\n");
	// printf("%.10xis a big number", (unsigned int)-1);
	// printf("\n");
	// printf("%.10Xis a big number", (unsigned int)-1);
	// printf("\n");
	// printf("%.0xis a big number", (unsigned int)-1);
	// printf("\n");
	// printf("%.0Xis a big number", (unsigned int)-1);
	// printf("\n");
	// printf("%.11xps a big number", (unsigned int)-1);
	// printf("\n");
	// printf("%.11Xps a big number", (unsigned int)-1);
	// printf("\n");
	// printf("the number is %.0x", (unsigned int)-1);
	// printf("\n");
	// printf("the number is %.0X", (unsigned int)-1);
	// printf("\n");
	// printf("the number is %.x", (unsigned int)-1);
	// printf("\n");
	// printf("the number is %.X", (unsigned int)-1);
	// printf("\n");
	// printf("the number is %.11x", (unsigned int)-1);
	// printf("\n");
	// printf("the number is %.11X", (unsigned int)-1);
	// printf("\n");
	// printf("%.0xis a big number", 0);
	// printf("\n");
	// printf("%.0Xis a big number", 0);
	// printf("\n");
	// printf("the number is %.0x", 0);
	// printf("\n");
	// printf("the number is %.0X", 0);
	// printf("\n");
	// printf("the number is %.x", 0);
	// printf("\n");
	// printf("the number is %.X", 0);
	// printf("\n");
	// printf("the number is %.5x", 0);
	// printf("\n");
	// printf("the number is %.5X", 0);
	// printf("\n");
	// printf("%x%.5x%.0x%.x%.9x", 5, 55, 2, 0, 42);
	// printf("\n");
	// printf("%X%.5X%.0X%.X%.9X", 5, 55, 2, 0, 42);
	// printf("\n");
	// printf("%xs%.5xi%.0xc%.xp%.9xu", 5, 55, 2, 0, 42);
	// printf("\n");
	// printf("%Xs%.5Xi%.0Xc%.Xp%.9Xu", 5, 55, 2, 0, 42);


	printf("\n");

	printf("\n");

	printf("\n");

	printf("\n");

	printf("\n");

	printf("\n");

	printf("\n");

	printf("\n");

	printf("\n");

	printf("\n");

	printf("\n");

	printf("\n");

	printf("\n");

	printf("\n");

	printf("\n");

	printf("\n");

	printf("\n");

	printf("\n");

	printf("\n");

	printf("\n");

	printf("\n");

	printf("\n");

	printf("\n");

	printf("\n");

	printf("\n");

	printf("\n");

	printf("\n");
}