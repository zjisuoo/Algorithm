#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_matching(const char *in) 
{
	StackType s;
	char ch, open_ch; 
	int i, n = strlen(in); 
	init_stack(&s);

	for (i = 0; i < n; i++) 
		{ 
			ch = in[i];
			switch (ch) 
			{ 
				case '(': case '[': case '{': 
				push(&s, ch);
				break;
				case ')': case ']': case '}':
				if (is_empty(&s)) 
					return 0; 
				else 
				{
					open_ch = pop(&s);
					if ((open_ch == '(' && ch != ')') || 
						(open_ch == '[' && ch != ']') ||
						(open_ch == '{' && ch != '}'))
					{
						return 0;
					}	
					break;
				}
			}
		}
		if (!is_empty(&s)) 
			return 0; 
		return 1;
}
int main(void) 
{
	char *p = "{ A[(i+1)]=0; }"; 

	if (check_matching(p) == 1)
		printf("%s 괄􏰨호검사성공\n", p);
	else
		printf("%s 괄􏰨호검사실패􏰪\n", p);
		return 0; 
}
