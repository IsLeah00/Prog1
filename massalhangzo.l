%{
	
	int consonant_cnt=0;
	int vowel_cnt=0;
%}

consonant [bcdfghjklmnpqrstvwxyzQWRTZPSDFGHJKLYXCVBNM]
vowel [aeuioöüóőúéáűEIUOŐÚÓÜÖAÉÁŰÍ]

eol \n

%%

{eol} return 0;

[\t]+ ;

{consonant} {consonant_cnt++;}
{vowel} {vowel_cnt++;}




%%

int main()

{
	printf("\n Adjon meg egy szöveget:\n");

	yylex();

	printf("\n Mássalhangzók száma = %d\n",consonant_cnt);
	printf("\n Magánhangzók száma = %d\n",vowel_cnt);

	return 0;
}

int yywrap()
{
	return 1;
}
