
          int n = strlen(str);
    char *s3 = str + n - 1; 
    if (isspace(*s3) && *(s3 - 1) != '.')   
        *s3 = '.';
    if (*s3 != '.')
        *(s3 + 1) = '.';