#include <stdio.h>

int main(void) {
  int pessoas, pe1, ps1, pd, di=0, aux1, aux2, pe2, ps2;
  printf("Quantas pessoas entrarão na escada rolante? ");
  scanf("%d", &pessoas);

  for(aux1=1; aux1<=pessoas; aux1++){
    printf("Momento da %d a pessoa entrar na escada rolante\n", aux1);
    scanf("%d", &pe1);
    printf("Direção da %d pessoa: ", aux1);
    scanf("%d", &pd);
    if (pd==di){
      ps1=pe1+10;
      printf("Saida da %d pessoa: %d\n", aux1, ps1);
    } else {
      ps1=pe1+12; 
      printf("Saida da %d pessoa: %d\n", aux1, ps1);
    }
  }
}
