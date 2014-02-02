/*	Rachel Biniaz
	Software Systems spring 2014
	Homework 01
	
	Calculates the current card count based on user inputted card names.
*/
#include <stdio.h>
#include <stdlib.h>

/*	Prompts the user for a card name and puts the reply in the given buffer.
	User input is truncated to the first two characters.
	card_name: buffer where result is stored
*/
void get_card_name(char *card_name) {
	puts("Enter the card name: ");
	scanf("%2s", card_name);
}

/*	Returns the value of the supplied card name.
	Returns -1 for 'X' and 0 for all other invalid card names.
	card_name: name of the card
*/
int get_card_value(char * card_name) {
	int val = 0;
	switch(card_name[0]){
	case 'K':
	case 'Q':
	case 'J':
		val = 10;
		break;
	case 'A':
		val = 11;
		break;
	case 'X':
		val = -1;
		break;
	default:
		val = atoi(card_name);
		if ((val < 2) || (val > 10)) {
			val = 0;
			break;
		}
	}
	return val;
}

/*	Updates the supplied count with the provided card value and prints the updated count.
	count: location of the count to be updated.
	card_value: value of the card to update the count with.
*/
void update_count(int *count, int card_value) {
	if ((card_value > 2) && (card_value < 7)) {
			(*count)++;
		} else if (card_value == 10) {
			(*count)--;
		}
		printf("Current count: %i\n", *count);
}

int main() {
	char card_name[3];
	int count = 0;
	while (card_name[0] != 'X') {
		int val; 
		get_card_name(card_name);
		val = get_card_value(card_name);
		if (val == -1) {
			continue;
		} else if (val == 0) {
			puts("I don't understand that value!");
			continue;	
		}
		update_count(&count, val);
	}	
	return 0;
}