# ButtonLib - Libreria per la gestione dei pulsanti con debounce e long press

## Descrizione
ButtonLib è una libreria per Arduino che semplifica la gestione dei pulsanti, implementando automaticamente il debounce e il rilevamento della pressione prolungata (long press).

## Funzionalità
- **Debounce automatico**: Evita il rimbalzo dei contatti.
- **Rilevamento della pressione normale**: Verifica se il pulsante è premuto.
- **Rilevamento della pressione prolungata**: Determina se il pulsante è stato premuto per un tempo superiore a una soglia definita.

## Dipendenze
- Arduino IDE
- Microcontrollore compatibile con Arduino

## Installazione
1. Copia i file `ButtonLib.h` e `ButtonLib.cpp` nella cartella del tuo progetto Arduino.
2. Includi l'header nel tuo sketch:
   ```cpp
   #include "ButtonLib.h"
   ```

## Utilizzo
### Dichiarazione di un oggetto Button
Per inizializzare un pulsante specificando il pin, il ritardo di debounce e il ritardo per il long press:
```cpp
Button button(2, 50, 1000); // Pin 2, debounce di 50 ms, long press di 1000 ms
```

### Inizializzazione
Nel `setup()`, chiama il metodo `begin()` per impostare il pin in modalità input:
```cpp
void setup() {
    button.begin();
}
```

### Aggiornamento dello stato del pulsante
Nel `loop()`, chiama `update()` per aggiornare lo stato del pulsante:
```cpp
void loop() {
    button.update();
    
    if (button.isPressed()) {
        Serial.println("Pulsante premuto!");
    }
    
    if (button.isLongPressed()) {
        Serial.println("Pulsante premuto a lungo!");
    }
}
```

## API
### `Button(int pin, unsigned long debounceDelay, unsigned long longPressDelay)`
Crea un oggetto pulsante.
- **pin**: Il numero del pin a cui è collegato il pulsante.
- **debounceDelay**: Il tempo di debounce in millisecondi.
- **longPressDelay**: Il tempo necessario per considerare una pressione come "long press".

### `void begin()`
Inizializza il pin del pulsante.

### `void update()`
Aggiorna lo stato del pulsante. Deve essere chiamato frequentemente nel `loop()`.

### `bool isPressed()`
Ritorna `true` se il pulsante è premuto.

### `bool isLongPressed()`
Ritorna `true` se il pulsante è stato premuto per un tempo superiore a `longPressDelay`.

## Esempio Completo
```cpp
#include "ButtonLib.h"

Button button(2, 50, 1000);

void setup() {
    Serial.begin(9600);
    button.begin();
}

void loop() {
    button.update();
    
    if (button.isPressed()) {
        Serial.println("Pulsante premuto!");
    }
    
    if (button.isLongPressed()) {
        Serial.println("Pulsante premuto a lungo!");
    }
}
```

