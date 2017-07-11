#ifndef __METEORITO_HXX
#define __METEORITO_HXX

defM::defM(){
	year="0";
	nombreMeteo="";
	masa=0;
	caidoEncontrado=false;
	latitud=0;
	longitud=0;
}
defM::defM(const defM & x){
	this->tipo.clear();
	this->tipo = x.getCodes();
	this->year = x.getYear();
	this->masa = x.getMas();
	this->caidoEncontrado= x.getFall();
	this->latitud = x.getLat();
	this->longitud = x.getLong();
}
bool defM::setCode(const string & s){
	this->tipo.push_back(s);
}
void defM::setMas(const double &  m){
	this->masa=m;
}
void defM::setFall(bool f){
	this->caidoEncontrado= f;
}
void defM::setYear(const string & y){
	this->year=y;
}
void defM::setLat(const double & lat){
	this->latitud = lat;
}
void defM::setLong(const double & longi){
	this->longitud= longi;
}
vector<string> defM::getCodes() const{
	return this->tipo;
}
double defM::getMas() const{
	return this->masa;
}
bool defM::getFall() const{
	return this->caidoEncontrado;
}
string defM::getYear() const{
	return this->year;
}
double defM::getLat() const{
	return this->latitud;
}
double defM::getLong() const{
	return this->longitud;
}

ostream & operator<< ( ostream &os , const defM &meteo ){
	string aux="";
	for(int i=0;i<(meteo.getCodes()).size();i++)
	{
		aux+=(meteo.getCodes())[i];
	}
	os <<"Masa:"<<meteo.getMas()<<"Año:"<<meteo.getYear()<<"Latitud:"<<meteo.getLat()<<"Longitud:"<<meteo.getLong()<<"Caido/encontrado:"<<meteo.getFall()<<"tipo:"<<aux<<endl;
	return os;
}
#endif
