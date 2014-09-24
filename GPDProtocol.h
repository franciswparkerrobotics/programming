//General Power Distribution Protocol
int checkBattery(float powerp){
float avgbLVL = nAvgBatteryLevel;
float float totalVwant;
//converts input to decimal
powerp = powerp / 100;
//gets milivoltage out of max number of voltage
totalVwant = powerp * 12000;
//gets percent of power needed. milivoltage of max power / milivoltage of power availible;
powerp = totalVwant / avgbLVL;
//turns percent back into input
powerp = power * 100
if(powerp >= 100){
  powerp = 100;
}
return powerp;
}
