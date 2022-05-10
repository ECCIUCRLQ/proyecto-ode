[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7705717&assignment_repo_type=AssignmentRepo)

# Cámara virtualizada utilizando Simics
Este proyecto utiliza la herramienta [Simics](https://www.intel.com/content/www/us/en/developer/articles/tool/simics-simulator.html), una plataforma que permitirá simular un dispositivo (en este caso una cámara) que se conectará a algún computador mediante un puerto [PCI](https://pcisig.com/specifications). Dicho dispositivo podrá tomar fotos, aplicar filtros, además el proyecto incluirá una aplicación para el usuario con la cual realizar dichas acciones y poder visualizar los resultados.

## 🗃️ Tabla de contenidos
- [Guía de compilación](#-guía-de-compilación)
- [Como utilizarlo](#-como-utilizarlo)
- [Funcionalidad básica](#-funcionalidad-básica)
- [Diseño](#-diseño)
- [Protocolo](#-protocolo)
- [Cosas por hacer](#-cosas-por-hacer)
- [Autores, Licencia](#-autores)

## 📦 Guía de compilación
Por hacer...
## 🚀 Como usarlo
Por hacer...
## 📷 Funcionalidad básica
Esta cámara virtual empleará el formato de archivo [BMP][1]. Por limitaciones del proyecto, la captura de fotografías se basará en tomar una imagen aleatoria preinstalada en el dispositivo y enviarla como resultado, ha esta se le podrán aplicar distintos [filtros](#filtros) para cambiar su apariencia, además de incluir metadatos de la imagen, como fecha de captura, tamaño, etc.
### Archivos BMP
Los archivos con formato [BMP][1] permiten guardar imagenes dentro de una computadora, estos poseen las siguientes estructuras[^1]:
| Estructura          | Bytes correspondientes  |
|:-------------------:|:-----------------------:|
| BITMAPFILEHEADER    | 0x00 0x0D               |
| BITMAPINFOHEADER    | 0x0E 0x35               |
| Arreglo RGBQUAD     | 0x36 0x75               |
| Arreglo Color-index | 0x76 0x275              |  
[^1]: Tomada de [Microsoft](https://docs.microsoft.com/en-us/windows/win32/gdi/bitmap-storage)


1. **BITMAPFILEHEADER**: permite indentificar el tipo de archivo (están en [little-endian](https://www.techopedia.com/definition/12892/little-endian)).
2. **BITMAPINFOHEADER**: contiene la información sobre las dimensiones y el formato de color[^3].
3. **RGBQUAD**: provee la intensidad de los colores RGB.
4. **Color-index**: contenido de la image.


[^2]: Tomado de [Fleformat](https://docs.fileformat.com/image/bmp/)
[^3]: Tomado de [Microsoft](https://docs.microsoft.com/en-us/previous-versions//dd183376(v=vs.85))
### Filtros
- Vintage
- Blur
- Negativo
- Blanco y negro
## 🎨 Diseño
Por hacer...
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
