#pragma once
class Persona {
private:
  string nombre;
  int dinero;
  int creditos;
  int monedas;
  int billetes;
  int papeles;
public:
  Persona() {
    nombre = "a" + to_string(rand() % 10) + to_string(rand() % 10) +
             to_string(rand() % 10) + to_string(rand() % 10);
    dinero = rand() % 100001;
    creditos = rand() % 100001;
    monedas = rand() % 1001;
    billetes = rand() % 100001;
    papeles = rand() % 10001;
  }

  string getNombre() { return nombre; }

  void setNombre(string nombre) { this->nombre = nombre; }

  int getDinero() { return dinero; }

  void setDinero(int dinero) { this->dinero = dinero; }

  int getCreditos() { return creditos; }

  void setCreditos(int creditos) { this->creditos = creditos; }

  int getMonedas() { return monedas; }

  void setMonedas(int monedas) { this->monedas = monedas; }

  int getBilletes() { return billetes; }

  void setBilletes(int billetes) { this->billetes = billetes; }

  int getPapeles() { return papeles; }

  void setPapeles(int papeles) { this->papeles = papeles; }
};