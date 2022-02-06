#include <iostream>
#include <time.h>

using namespace std;

bool checks(bool num, bool low, bool upp, bool spe, bool len, bool consec) {

	// Make sure all values evaluate to true
	if (num == low && low == upp && upp == spe && spe == len && len == consec && consec == true)
		return true;

	return false;
}


int main() {

	srand(time(NULL));

	// Var declaration, initialization
	int passLen = 0;
	int n = 0;

	char randChar[94] = { '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~' };
	char pass[20];

	bool numCheck = false;
	bool lowCheck = false;
	bool uppCheck = false;
	bool speCheck = false;
	bool lenCheck = false;
	bool consecCheck = false;

	while (!checks(numCheck, lowCheck, uppCheck, speCheck, lenCheck, consecCheck)) {

		passLen = rand() % 11 + 10;

		for (int i = 0; i < passLen; i++) {

			n = rand() % 94;

			if (i > 1 && i < passLen - 1) {

				// Consecutive check
				while (n - 1 == pass[i - 1] && n + 1 == pass[i + 1])
					n = rand() % 94;

			}

			if (pass[i] >= 'a' && pass[i] <= 'z')
				lowCheck = true;// Lowercase check

			if (pass[i] >= 'A' && pass[i] <= 'Z')
				uppCheck = true; // Uppercase check

			if (pass[i] >= '0' && pass[i] <= '9')
				numCheck = true; // Number check

			if (passLen >= 10)
				lenCheck = true; // passLen check

			if (pass[i] >= ' ' && pass[i] <= '/' || pass[i] >= ':' && pass[i] <= '@' || pass[i] >= '[' && pass[i] <= '`' || pass[i] >= '{' && pass[i] <= '~') {
				speCheck = true; // Special Character check

			pass[i] = randChar[n];

			for (int n = 1; n < passLen - 1; n++)
				if (pass[n - 1] != pass[n] - 1 && pass[n + 1] != pass[n] + 1)
					consecCheck = true;

		}

		if (!checks(numCheck, lowCheck, uppCheck, speCheck, lenCheck, consecCheck)) {
			numCheck = false;
			lowCheck = false;
			uppCheck = false;
			speCheck = false;
			lenCheck = false;
			consecCheck = false;

			continue;
		}
	}

	cout << "Generated Password: ";

	for (int i = 0; i < passLen; i++)
		cout << pass[i];

	return 0;
}
