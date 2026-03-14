#include "../app/shell.h"

int main(void)
{
    shell_execute("HELP");
    shell_execute("LED_ON");
    shell_execute("TEMP");
    shell_execute("ABC");
    shell_execute("EXIT");
    
    return 0;
}