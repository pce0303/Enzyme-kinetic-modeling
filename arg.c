#include <stdio.h>
#include <math.h>

double calcRate(double T, int A, double Ea);
void drawGraph(double activationEnergy);

int main() {
  double temperature; //온도
  printf("온도를 입력하세요 (°C) : ");
  scanf("%lf", &temperature);

  int collisions; //충돌 횟수
  printf("선행인자 값을 입력하세요 (양의 정수) : ");
  scanf("%d", &collisions);

  double Energy; //활성화 에너지
  printf("활성화 에너지 값을 입력하세요 (20kJ/mol ~ 200kJ/mol): ");
  scanf("%lf", &Energy);

  printf("\n활성화 에너지 그래프 : \n");
  drawGraph(Energy); //활성화 에너지 그래프

  double Rate = calcRate(temperature, collisions, Energy);
  printf("이 효소의 반응 속도 상수는 %e 입니다.\n", Rate);  //반응 속도 출력

  return 0;
}

double calcRate(double T, int A, double Ea) {
  const double R = 8.314; //기체 상수

  double k = A * exp(-Ea / ( R * (T+273))); //반응 속도 계산
  // 자연상수 e의 지수제곱 exp 함수

  return k;
}

void drawGraph(double activationEnergy) {
    int i, j;
    int maxEnergy = 20;  // 그래프의 최대 높이
    int width = 20;      // 그래프의 폭
    double pi = 3.14159;

    // 활성화 에너지 함수
    for (i = 0; i < width; i++) {
        double activationFunction = -pow((double)i / width, 2) * activationEnergy;

        // 그래프 출력
        int height = activationFunction + maxEnergy;
        for (j = 0; j < height; j++) {
            if (j == maxEnergy) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("*\n");
    }
}