#include <stdio.h>

#include "error.h"
#include "define.h"

int show_error(int rc)
{
	switch (rc)
	{
	case 1: printf("INPUT_ERROR"); break;
	case 2: printf("ROW_COL_VALUE_ERROR"); break;
	case 3: printf("MALLOC_ERROR"); break;
	case 4: printf("ARG_ERROR"); break;
	case 5: printf("FILE_OPEN_ERROR"); break;
	case 6: printf("NOT_SQUARE_MATRIX"); break;
	case 7: printf("NO_ELEMENT_FOUND"); break;
	default:
		break;
	}
	return rc;
}

