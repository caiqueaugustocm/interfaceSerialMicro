#include <mbed.h>

PwmOut led(LED1);

Serial pc(USBTX, USBRX, 9600);

char input;
float ledIntensity;

void getValue();
void changeIntensity();

int main() {
  pc.attach(&getValue);
}

void getValue()
{
  input = pc.getc();
  changeIntensity();
}

void changeIntensity(){
  switch(input)
    {
      case '+':
        if (ledIntensity >= 1.0f)
          ledIntensity = 1.0f;
        else
          ledIntensity += 0.5f;
        break;
      case '-':
        if (ledIntensity <= 0.0f)
          ledIntensity = 0.0f;
        else
          ledIntensity -= 0.5f;
        break;
      case '*':
        ledIntensity = 1.0f;
        break;
      case '/':
        ledIntensity = 0.0f;
        break;
      default:
        pc.printf("Invalid character!\n");
        break;
    }
    led.write(ledIntensity);
    pc.printf("Led Intensity is: %.2f\n",ledIntensity);
}