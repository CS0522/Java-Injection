rm *.so
flex -d -o ognl.c grammar/ognl.l
bison -vd grammar/ognl.y -o ognl.tab.c
rm ognl.output
python3 script/gen_file.py --input ognl.tab.h
python3 script/gen_file.py --input ognl.tab.c
python3 script/gen_file.py --input ognl.c
mv *.tab.c grammar_gen/
mv ognl.c grammar_gen/
mv *.h include/
gcc -g -O3 -Wno-implicit-function-declaration grammar_gen/ognl_lex.c app/main_detec.c grammar_gen/ognl.c grammar_gen/ognl.tab.c -shared -fPIC -o ./detection.so
rm -r *.dSYM
echo "Making engine/detection finished"
# cp ../../conf/ognl.y grammar/  && bison -vd grammar/ognl.y -o ognl.tab.c
# bison -vd grammar/ognl.y -o ognl.tab.c -Wcounterexamples
