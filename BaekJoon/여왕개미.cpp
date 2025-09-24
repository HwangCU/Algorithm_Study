#include <iostream>
#include <vector>

using namespace std;

// 전역 변수들을 선언합니다.
// totalCommands는 총 명령의 개수를 저장하는 변수입니다.
int totalCommands;

// anthillDeleted 벡터는 각 개미집의 철거 여부를 저장합니다.
// 인덱스 0은 사용하지 않지만, 인덱스 번호를 1부터 사용하기 위해 초기에 하나의 값을 추가합니다.
vector<bool> anthillDeleted(1);

// anthillPositions 벡터는 각 개미집의 x좌표 위치를 저장합니다.
// 인덱스 0은 여왕 개미의 개미집 (x = 0)을 의미하며, 이후 인덱스 1부터 실제 개미집이 저장됩니다.
vector<int> anthillPositions(1);

// 초기 마을 건설 명령을 처리하는 함수를 정의합니다.
// 이 함수는 형식 "100 N x1 x2 ... xN"의 입력을 읽어 들여, 여왕 개미의 집 (x=0)과 N개의 개미집을 건설합니다.
void initialVillageConstruction() {
	// 마을 건설 명령에서는 처음에 N개의 개미집을 건설하는 명령이 주어집니다.
	// numInitialAnthills 변수에 건설할 개미집의 수를 저장합니다.
	int numInitialAnthills;
	cin >> numInitialAnthills;

	// 여왕 개미가 사는 개미집은 x=0에 건설되며, 이미 anthillPositions 벡터에 0번째에 저장되어 있습니다.
	// 이후 1번부터 numInitialAnthills까지 개미집을 건설합니다.
	// 각 개미집의 위치는 입력으로 주어지며, 오름차순 순서로 주어짐이 보장됩니다.
	for (int i = 1; i <= numInitialAnthills; i++) {
		int position;
		cin >> position;
		// anthillPositions 벡터의 맨 뒤에 개미집의 위치를 추가합니다.
		anthillPositions.push_back(position);
		// anthillDeleted 벡터에도 false를 추가하여 해당 개미집이 철거되지 않았음을 기록합니다.
		anthillDeleted.push_back(false);
	}
}

// 새로운 개미집 건설 명령을 처리하는 함수를 정의합니다.
// 이 함수는 형식 "200 p"의 입력을 읽어 들여, x = p 위치에 새 개미집을 건설합니다.
void addNewAnthill() {
	// 새로운 개미집의 위치를 저장할 변수를 선언합니다.
	int newAnthillPosition;
	cin >> newAnthillPosition;

	// anthillPositions 벡터의 맨 뒤에 새로운 개미집의 위치를 추가합니다.
	// 문제에서 p는 기존 개미집의 위치보다 반드시 큰 값입니다.
	anthillPositions.push_back(newAnthillPosition);

	// anthillDeleted 벡터에도 false를 추가하여 새 개미집이 철거되지 않았음을 기록합니다.
	anthillDeleted.push_back(false);
}

// 개미집 철거 명령을 처리하는 함수를 정의합니다.
// 이 함수는 형식 "300 q"의 입력을 읽어 들여, q번 개미집을 철거 상태로 변경합니다.
void removeAnthill() {
	// 철거할 개미집의 번호를 저장할 변수를 선언합니다.
	int anthillNumber;
	cin >> anthillNumber;

	// anthillDeleted 벡터에서 해당 번호의 값을 true로 설정함으로써 개미집이 철거되었음을 나타냅니다.
	anthillDeleted[anthillNumber] = true;
}

// 개미집 정찰(스카우트) 명령을 처리하는 함수를 정의합니다.
// 이 함수는 형식 "400 r"의 입력을 읽어 들여, r마리의 일 개미가 정찰을 진행할 때 걸리는 최소 시간을 계산하여 출력합니다.
void processScoutQuery() {
	// 정찰에 나갈 일 개미의 수를 입력받아 numAnts 변수에 저장합니다.
	int numAnts;
	cin >> numAnts;

	// 문제에서는 주어진 r마리의 개미가 개미집을 선택할 때, 모든 개미집이 '안전한 개미집'이 될 수 있도록 최소 시간을 구하는 것이 목표입니다.
	// 이를 위해 이진 탐색을 사용하여 최소 시간 T를 구합니다.

	// lowerBound와 upperBound를 이진 탐색의 범위로 설정합니다.
	// lowerBound는 최소 시간 0, upperBound는 최대 시간 10^9로 설정합니다.
	int lowerBound = 0;
	int upperBound = anthillPositions[anthillPositions.size()-1];

	// minimumTime 변수에는 현재까지 가능한 최소 시간을 저장합니다.
	int minimumTime = 0;

	// 이진 탐색을 수행합니다.
	while (lowerBound <= upperBound) {
		// 현재 탐색 범위의 중간값을 midTime으로 설정합니다.
		int midTime = (lowerBound + upperBound) / 2;

		// intervalsNeeded 변수는 midTime 내에 하나의 개미가 커버할 수 있는 영역으로 필요로 하는 구간의 수를 저장합니다.
		int intervalsNeeded = 0;

		// lastCoveredPosition 변수는 이전에 커버된 마지막 개미집의 위치를 저장합니다.
		// 초기값으로 충분히 낮은 값을 설정합니다.
		int lastCoveredPosition = -1000000000;

		// anthillPositions 벡터에 저장된 각 개미집을 순서대로 살펴봅니다.
		// 인덱스 0은 여왕 개미의 개미집이므로, 인덱스 1부터 실제 개미집의 위치에 대해 검토합니다.
		for (size_t i = 1; i < anthillPositions.size(); i++) {
			// 만약 현재 개미집이 철거된 상태라면 건너뜁니다.
			if (anthillDeleted[i])
				continue;

			// 현재 개미집의 위치를 currentAnthillPosition 변수에 저장합니다.
			int currentAnthillPosition = anthillPositions[i];

			// 만약 현재 개미집과 이전에 커버된 마지막 개미집 사이의 거리가 midTime보다 크다면,
			// 새로운 구간(즉, 새로운 일 개미가 출발하여 이 개미집부터 커버를 시작함)을 추가해야 합니다.
			if (currentAnthillPosition - lastCoveredPosition > midTime) {
				// 새로운 구간의 시작점을 현재 개미집의 위치로 설정합니다.
				lastCoveredPosition = currentAnthillPosition;
				// 구간의 수를 1 증가시킵니다.
				intervalsNeeded++;
			}
		}

		// 만약 필요한 구간의 수가 numAnts보다 작거나 같다면,
		// 주어진 midTime 내에 가능한 정찰이 가능하다는 의미입니다.
		if (intervalsNeeded <= numAnts) {
			// midTime 값을 가능한 최소 시간으로 갱신합니다.
			minimumTime = midTime;
			// 더 작은 시간으로 정찰이 가능한지 확인하기 위해 upperBound를 midTime - 1로 조정합니다.
			upperBound = midTime - 1;
		}
		else {
			// 만약 필요한 구간의 수가 numAnts보다 많다면,
			// midTime이 너무 작다는 의미이므로 lowerBound를 midTime + 1로 조정합니다.
			lowerBound = midTime + 1;
		}
	}

	// 이진 탐색을 마친 후, 계산된 최소 정찰 시간을 출력합니다.
	cout << minimumTime << "\n";
}

// 메인 함수를 정의합니다.
int main() {
	// 입출력 속도를 개선하기 위해 동기화를 해제하고, cin.tie를 nullptr로 설정합니다.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 총 명령의 수를 입력받아 totalCommands 변수에 저장합니다.
	cin >> totalCommands;

	// totalCommands만큼 반복하면서 각 명령을 처리합니다.
	while (totalCommands--) {
		// 각 명령의 종류를 저장할 변수를 선언하고 입력받습니다.
		int commandType;
		cin >> commandType;

		// commandType이 100이면 마을 건설 명령이므로 initialVillageConstruction 함수를 호출합니다.
		if (commandType == 100) {
			initialVillageConstruction();
		}
		// commandType이 200이면 개미집 건설 명령이므로 addNewAnthill 함수를 호출합니다.
		else if (commandType == 200) {
			addNewAnthill();
		}
		// commandType이 300이면 개미집 철거 명령이므로 removeAnthill 함수를 호출합니다.
		else if (commandType == 300) {
			removeAnthill();
		}
		// commandType이 400이면 개미집 정찰 명령이므로 processScoutQuery 함수를 호출합니다.
		else if (commandType == 400) {
			processScoutQuery();
		}
	}

	return 0;
}

