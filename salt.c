#include <stdio.h>
#include <time.h>
#include <stdint.h>

uint64_t mix(time_t n);

int main(){
    time_t arbitrary_num;
    time(&arbitrary_num);
    uint64_t random_output = mix(arbitrary_num);
    printf("%lld testing!!!!!\nString: {", random_output);
    char str[9];
    for(uint8_t i = 0; i < 9; i++){
        str[i] = random_output%100+32;
        printf("%c", str[i]);
        random_output /= 100;
    }
    printf("}\n done!!!");

}

uint64_t mix(time_t n){
    uint64_t mix = (n+16)/2;
    mix *= mix;
    mix /= 2;
    mix *= mix%3 + 1;
    mix /= 500;
    mix *= mix%7 + 1;
    mix /= 5000;
    mix *= 1111111;
    return mix;
}
