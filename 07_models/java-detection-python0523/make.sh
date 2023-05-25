cp conf/ognl* engine/detection/grammar/
cd engine/detection && sh make.sh
cd ../..
mv engine/detection/detection.so engine/
python3 script/update.py
