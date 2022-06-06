[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7705717&assignment_repo_type=AssignmentRepo)


# Cámara virtualizada utilizando Simics
Este proyecto utiliza la herramienta [Simics](https://www.intel.com/content/www/us/en/developer/articles/tool/simics-simulator.html), una plataforma que permitirá simular un dispositivo (en este caso una cámara) que se conectará a algún computador mediante un puerto [PCI](https://pcisig.com/specifications). Dicho dispositivo podrá tomar fotos, aplicar filtros, además el proyecto incluirá una aplicación para el usuario con la cual realizar dichas acciones y poder visualizar los resultados.


## 🗃️ Tabla de contenidos
- [Guía de compilación](#-guía-de-compilación)
- [Como usarlo](#-como-usarlo)
- [Funcionalidades básicas](#-funcionalidades-básicas)
- [Diseño](#-diseño)
- [Protocolo](#-protocolo)
- [Cosas por hacer](#-cosas-por-hacer)
- [Autores, licencia](#-autores)


## 📦 Guía de compilación
Por hacer...


## 🚀 Como usarlo
Por hacer...


## 📷 Funcionalidades básicas

Esta cámara virtual empleará el formato de archivo [BMP](https://github.com/ECCIUCRLQ/proyecto-ode/wiki/Bitmap). Por limitaciones del proyecto, la captura de fotografías se basará en tomar una imagen aleatoria preinstalada en el dispositivo y enviarla como resultado, ha esta se le podrán aplicar distintos [filtros](https://github.com/ECCIUCRLQ/proyecto-ode/wiki/Dispositivo#filtros) para cambiar su apariencia, además de incluir metadatos de la imagen, como fecha de captura, tamaño, etc.

### Filtros 🪟

Estos son los filtros que  se le podrán aplicar a las fotos:

[normal]: https://github.com/ECCIUCRLQ/proyecto-ode/blob/main/doc/img/imagen_referencia_normal.jpg "Imagen de referencia normal"
[vintage]: https://github.com/ECCIUCRLQ/proyecto-ode/blob/main/doc/img/imagen_referencia_vintage.jpg "Imagen de referencia con filtro vintage"
[blur]: https://github.com/ECCIUCRLQ/proyecto-ode/blob/main/doc/img/imagen_referencia_blur.jpg "Imagen de referencia con filtro blur"
[negativo]: https://github.com/ECCIUCRLQ/proyecto-ode/blob/main/doc/img/imagen_referencia_negativo.jpg "Imagen de referencia con filtro negativo"
[b&n]: https://github.com/ECCIUCRLQ/proyecto-ode/blob/main/doc/img/imagen_referencia_b%26w.jpg "Imagen de referencia con filtro blanco y negro"

<details>
  <summary>Vintage</summary>
  
| ![alt text][normal] | ![alt text][vintage] |
|:-------------------:|:--------------------:|
  
  El filtro vintage le da una apariencia antigua a las fotos.
</details>

<details>
  <summary>Blur</summary>
  
| ![alt text][normal] | ![alt text][blur] |
|:-------------------:|:-----------------:|
  
  Este filtro genera un desenfoque artificial en toda la foto.
</details>

<details>
  <summary>Negativo</summary>
  
| ![alt text][normal] | ![alt text][negativo] |
|:-------------------:|:---------------------:|
  
  Con este filtro los blancos son tratados como negros y los negros como blancos.
</details>

<details>
  <summary>Blanco y negro</summary>
  
| ![alt text][normal] | ![alt text][b&n] |
|:-------------------:|:----------------:|
  
  Este filtro quita el color a las fotos.
</details>

> Las anteriores imágenes no representan el aspecto final del resultado de los filtros que va a aplicar el dispositivo.

## 🎨 Diseño
![alt text](https://github.com/ECCIUCRLQ/proyecto-ode/blob/main/doc/img/dise%C3%B1o.png)


El proyecto tiene distintos componentes que se interconectan entre ellos. El principal es el dispositivo que es una cámara, esta se conecta mediante PCI, ha algún computador, para que estos dos se puedan comunicar correctamente se necesita de un controlador. También es necesario de un programa que pueda utilizar el usuario para comunicarse con el dispositivo.


## 🧮 Protocolo
Es la forma en la que comunica el dispositivo con el driver, se implementará según un consenso de la clase.
## ✅ Cosas por hacer
- [X] Diseño del producto final
- [ ] Guía de compilación
- [ ] Como utilizarlo
- [ ] La especificación formal del dispositivo
- [ ] El controlador (driver)
- [ ] Un programa de usuario
- [ ] Pruebas de validación 
- [ ] Protocolo

## Habilidades y conocimientos necesarios
- Adquirir facilidad de programar en lenguaje ensamblador.
- Procesamiento y codificación de imágenes.
- Especificaciones y estructura de los archivos BMP.
- Mejor manipulación de Simics para adquirir comodidad al utilizarlo.
- Experiencia en desarrollo de aplicaciones que mezclen código de alto nivel con lenguaje ensamblador.
- Tener una mejor comprensión de la estructura PCI y su funcionamiento.

## 👤 Autores
Oscar Quesada Webb
- oscar.quesadawebb@ucr.ac.cr


David Sánchez López
- david.sanchezlopez@ucr.ac.cr


Esteban Porras Herrera
- esteban.porrasherrera@ucr.ac.cr


## 📝 Licencia
Este repositorio tiene una licencia [MIT](LICENSE)

[1]: https://docs.microsoft.com/en-us/windows/win32/gdi/bitmaps
