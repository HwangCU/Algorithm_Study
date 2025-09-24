#include <iostream>
#include <vector>

using namespace std;

// ���� �������� �����մϴ�.
// totalCommands�� �� ����� ������ �����ϴ� �����Դϴ�.
int totalCommands;

// anthillDeleted ���ʹ� �� �������� ö�� ���θ� �����մϴ�.
// �ε��� 0�� ������� ������, �ε��� ��ȣ�� 1���� ����ϱ� ���� �ʱ⿡ �ϳ��� ���� �߰��մϴ�.
vector<bool> anthillDeleted(1);

// anthillPositions ���ʹ� �� �������� x��ǥ ��ġ�� �����մϴ�.
// �ε��� 0�� ���� ������ ������ (x = 0)�� �ǹ��ϸ�, ���� �ε��� 1���� ���� �������� ����˴ϴ�.
vector<int> anthillPositions(1);

// �ʱ� ���� �Ǽ� ����� ó���ϴ� �Լ��� �����մϴ�.
// �� �Լ��� ���� "100 N x1 x2 ... xN"�� �Է��� �о� �鿩, ���� ������ �� (x=0)�� N���� �������� �Ǽ��մϴ�.
void initialVillageConstruction() {
	// ���� �Ǽ� ��ɿ����� ó���� N���� �������� �Ǽ��ϴ� ����� �־����ϴ�.
	// numInitialAnthills ������ �Ǽ��� �������� ���� �����մϴ�.
	int numInitialAnthills;
	cin >> numInitialAnthills;

	// ���� ���̰� ��� �������� x=0�� �Ǽ��Ǹ�, �̹� anthillPositions ���Ϳ� 0��°�� ����Ǿ� �ֽ��ϴ�.
	// ���� 1������ numInitialAnthills���� �������� �Ǽ��մϴ�.
	// �� �������� ��ġ�� �Է����� �־�����, �������� ������ �־����� ����˴ϴ�.
	for (int i = 1; i <= numInitialAnthills; i++) {
		int position;
		cin >> position;
		// anthillPositions ������ �� �ڿ� �������� ��ġ�� �߰��մϴ�.
		anthillPositions.push_back(position);
		// anthillDeleted ���Ϳ��� false�� �߰��Ͽ� �ش� �������� ö�ŵ��� �ʾ����� ����մϴ�.
		anthillDeleted.push_back(false);
	}
}

// ���ο� ������ �Ǽ� ����� ó���ϴ� �Լ��� �����մϴ�.
// �� �Լ��� ���� "200 p"�� �Է��� �о� �鿩, x = p ��ġ�� �� �������� �Ǽ��մϴ�.
void addNewAnthill() {
	// ���ο� �������� ��ġ�� ������ ������ �����մϴ�.
	int newAnthillPosition;
	cin >> newAnthillPosition;

	// anthillPositions ������ �� �ڿ� ���ο� �������� ��ġ�� �߰��մϴ�.
	// �������� p�� ���� �������� ��ġ���� �ݵ�� ū ���Դϴ�.
	anthillPositions.push_back(newAnthillPosition);

	// anthillDeleted ���Ϳ��� false�� �߰��Ͽ� �� �������� ö�ŵ��� �ʾ����� ����մϴ�.
	anthillDeleted.push_back(false);
}

// ������ ö�� ����� ó���ϴ� �Լ��� �����մϴ�.
// �� �Լ��� ���� "300 q"�� �Է��� �о� �鿩, q�� �������� ö�� ���·� �����մϴ�.
void removeAnthill() {
	// ö���� �������� ��ȣ�� ������ ������ �����մϴ�.
	int anthillNumber;
	cin >> anthillNumber;

	// anthillDeleted ���Ϳ��� �ش� ��ȣ�� ���� true�� ���������ν� �������� ö�ŵǾ����� ��Ÿ���ϴ�.
	anthillDeleted[anthillNumber] = true;
}

// ������ ����(��ī��Ʈ) ����� ó���ϴ� �Լ��� �����մϴ�.
// �� �Լ��� ���� "400 r"�� �Է��� �о� �鿩, r������ �� ���̰� ������ ������ �� �ɸ��� �ּ� �ð��� ����Ͽ� ����մϴ�.
void processScoutQuery() {
	// ������ ���� �� ������ ���� �Է¹޾� numAnts ������ �����մϴ�.
	int numAnts;
	cin >> numAnts;

	// ���������� �־��� r������ ���̰� �������� ������ ��, ��� �������� '������ ������'�� �� �� �ֵ��� �ּ� �ð��� ���ϴ� ���� ��ǥ�Դϴ�.
	// �̸� ���� ���� Ž���� ����Ͽ� �ּ� �ð� T�� ���մϴ�.

	// lowerBound�� upperBound�� ���� Ž���� ������ �����մϴ�.
	// lowerBound�� �ּ� �ð� 0, upperBound�� �ִ� �ð� 10^9�� �����մϴ�.
	int lowerBound = 0;
	int upperBound = anthillPositions[anthillPositions.size()-1];

	// minimumTime �������� ������� ������ �ּ� �ð��� �����մϴ�.
	int minimumTime = 0;

	// ���� Ž���� �����մϴ�.
	while (lowerBound <= upperBound) {
		// ���� Ž�� ������ �߰����� midTime���� �����մϴ�.
		int midTime = (lowerBound + upperBound) / 2;

		// intervalsNeeded ������ midTime ���� �ϳ��� ���̰� Ŀ���� �� �ִ� �������� �ʿ�� �ϴ� ������ ���� �����մϴ�.
		int intervalsNeeded = 0;

		// lastCoveredPosition ������ ������ Ŀ���� ������ �������� ��ġ�� �����մϴ�.
		// �ʱⰪ���� ����� ���� ���� �����մϴ�.
		int lastCoveredPosition = -1000000000;

		// anthillPositions ���Ϳ� ����� �� �������� ������� ���캾�ϴ�.
		// �ε��� 0�� ���� ������ �������̹Ƿ�, �ε��� 1���� ���� �������� ��ġ�� ���� �����մϴ�.
		for (size_t i = 1; i < anthillPositions.size(); i++) {
			// ���� ���� �������� ö�ŵ� ���¶�� �ǳʶݴϴ�.
			if (anthillDeleted[i])
				continue;

			// ���� �������� ��ġ�� currentAnthillPosition ������ �����մϴ�.
			int currentAnthillPosition = anthillPositions[i];

			// ���� ���� �������� ������ Ŀ���� ������ ������ ������ �Ÿ��� midTime���� ũ�ٸ�,
			// ���ο� ����(��, ���ο� �� ���̰� ����Ͽ� �� ���������� Ŀ���� ������)�� �߰��ؾ� �մϴ�.
			if (currentAnthillPosition - lastCoveredPosition > midTime) {
				// ���ο� ������ �������� ���� �������� ��ġ�� �����մϴ�.
				lastCoveredPosition = currentAnthillPosition;
				// ������ ���� 1 ������ŵ�ϴ�.
				intervalsNeeded++;
			}
		}

		// ���� �ʿ��� ������ ���� numAnts���� �۰ų� ���ٸ�,
		// �־��� midTime ���� ������ ������ �����ϴٴ� �ǹ��Դϴ�.
		if (intervalsNeeded <= numAnts) {
			// midTime ���� ������ �ּ� �ð����� �����մϴ�.
			minimumTime = midTime;
			// �� ���� �ð����� ������ �������� Ȯ���ϱ� ���� upperBound�� midTime - 1�� �����մϴ�.
			upperBound = midTime - 1;
		}
		else {
			// ���� �ʿ��� ������ ���� numAnts���� ���ٸ�,
			// midTime�� �ʹ� �۴ٴ� �ǹ��̹Ƿ� lowerBound�� midTime + 1�� �����մϴ�.
			lowerBound = midTime + 1;
		}
	}

	// ���� Ž���� ��ģ ��, ���� �ּ� ���� �ð��� ����մϴ�.
	cout << minimumTime << "\n";
}

// ���� �Լ��� �����մϴ�.
int main() {
	// ����� �ӵ��� �����ϱ� ���� ����ȭ�� �����ϰ�, cin.tie�� nullptr�� �����մϴ�.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// �� ����� ���� �Է¹޾� totalCommands ������ �����մϴ�.
	cin >> totalCommands;

	// totalCommands��ŭ �ݺ��ϸ鼭 �� ����� ó���մϴ�.
	while (totalCommands--) {
		// �� ����� ������ ������ ������ �����ϰ� �Է¹޽��ϴ�.
		int commandType;
		cin >> commandType;

		// commandType�� 100�̸� ���� �Ǽ� ����̹Ƿ� initialVillageConstruction �Լ��� ȣ���մϴ�.
		if (commandType == 100) {
			initialVillageConstruction();
		}
		// commandType�� 200�̸� ������ �Ǽ� ����̹Ƿ� addNewAnthill �Լ��� ȣ���մϴ�.
		else if (commandType == 200) {
			addNewAnthill();
		}
		// commandType�� 300�̸� ������ ö�� ����̹Ƿ� removeAnthill �Լ��� ȣ���մϴ�.
		else if (commandType == 300) {
			removeAnthill();
		}
		// commandType�� 400�̸� ������ ���� ����̹Ƿ� processScoutQuery �Լ��� ȣ���մϴ�.
		else if (commandType == 400) {
			processScoutQuery();
		}
	}

	return 0;
}

