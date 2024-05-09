#include <DHT.h>
#include <WiFi.h>

// Substitua pelas credenciais da sua rede Wi-Fi
const char* ssid = "Starlink"; // "SUA_REDE_WIFI"
const char* password = "diversao"; // "SUA_SENHA"

DHT dht(26, DHT11);

WiFiServer server(80); // Cria um servidor na porta 80

void setup() {
  

  dht.begin();
  delay(2000);

  Serial.begin(115200);



  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    Serial.println("Conectando ao WiFi...");
  }

  Serial.println("\nConectado ao WiFi!");
  Serial.println("Endereço de IP: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  float temp = dht.readTemperature();
  float umidade = dht.readHumidity();

  Serial.print("TEMP C ");
  Serial.print(temp);

  Serial.print(" -- Umidade ");
  Serial.print(umidade);
  Serial.println(" % ");
  
  /*
  WiFiClient client = server.available();
  if (client) {
    // Aqui você pode processar a comunicação com o cliente, 
    // por exemplo, enviando os dados de temperatura e umidade

    //client.stop();

    Serial.println(" *** cliente disponivel *** ");
  }
  */

  delay(2000);
}