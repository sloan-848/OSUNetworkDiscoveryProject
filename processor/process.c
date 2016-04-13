#import <stdio.h>
#import <string.h>

int main(void) {
  FILE *input = fopen("data.txt", "r");
  FILE *output = fopen("output.txt", "w");
  if (input == NULL) {
    perror("Failed to open file");
  }
  char *line = NULL;
  size_t linepos = 0;

  while ((getline(&line, &linepos, input)) > 0) {
    char temp[5];
    strncpy(temp, line, 4);
    temp[4] = '\0';
    char ip_address[32];
    if (strcmp(temp, "Nmap") == 0) {
      // Find end of line location
      int i = 0;
      for (; i < 256; i++) {
        if (line[i] == '\0') {
          break;
        }
      }
      // Check if there was DNS Resolution or not
      if (line[i-2] == ')') { // There was DNS resolution
        int j = 0;
        for(; j < i; j++) {
          if (line[j] == '(')
            break;
        }
        // j is beginning of IP address
        int size = i - j - 3;
        strncpy(ip_address, &line[j+1], size);
        ip_address[size] = '\0';
      } else {
        int j = 0;
        for (; j < i; j++) {
          if (line[j] >= '0' && line[j] <= '9')
            break;
        }
        // j is the beginning of the
        int size = i - j - 1;
        strncpy(ip_address, &line[j], size);
        ip_address[size] = '\0';
      }

      // Write to FILE
      fprintf(output, "%s\n", ip_address);
    }
  }
}
