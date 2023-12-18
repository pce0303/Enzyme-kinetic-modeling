#include <stdio.h>
#include <math.h>

double calcRate(double T, int A, double Ea);

int main() {
  double temperature; //온도
  printf("온도를 입력하세요 (°C) : ");
  scanf("%lf", &temperature);

  int collisions; //충돌 횟수
  printf("선행인자 값을 입력하세요 (양의 정수) : ");
  scanf("%d", &collisions);

  double Energy; //활성화 에너지
  printf("활성화 에너지 값을 입력하세요 (kJ/mol): ");
  scanf("%lf", &Energy);

  double Rate = calcRate(temperature, collisions, Energy);
  printf("이 효소의 반응 속도상수는 %e 입니다.\n", Rate);  //반응 속도 출력

  return 0;
}

double calcRate(double T, int A, double Ea) {
  const double R = 8.314; //기체 상수

  double k = A * exp(-Ea / ( R * (T+273))); //반응 속도 계산
  // 자연상수 e의 지수제곱 exp 함수

  return k;
}