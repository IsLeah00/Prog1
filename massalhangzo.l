%{
	
	int consonant_cnt=0;
%}

consonant [bcdfghjklmnpqrstvwxyz]

eol \n

%%

{eol} return 0;

[\t]+ ;

{consonant} {consonant_cnt++;}




%%

int main()

{
	printf("\n Adjon meg egy szöveget:\n");

	yylex();

	printf("\n Mássalhangzók száma = %d\n",consonant_cnt);

	return 0;
}

int yywrap()
{
	return 1;
}