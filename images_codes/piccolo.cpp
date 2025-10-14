#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "Headers/stb_image.h"
#include "Headers/stb_image_write.h"
#include <iostream>

int main(){
    int larguraPiccolo, alturaPiccolo, canaisPiccolo;
    unsigned char* imagemPiccolo = stbi_load("images/piccolo.jpg", &larguraPiccolo, &alturaPiccolo, &canaisPiccolo, 0);
    if(!imagemPiccolo){
        std::cout << "oh, não achei essa imagem não viu!" << std::endl;
        return -1;
    }
    std::cout << larguraPiccolo << "-" << alturaPiccolo << "-" << canaisPiccolo << std::endl;

    for(int y = 0; y < alturaPiccolo; y++){
        /*for(int x = 0; x < larguraPiccolo; x++){
            unsigned int indice = (y * larguraPiccolo + x) * canaisPiccolo;
            int mediaPixel = (imagemPiccolo[indice] + imagemPiccolo[indice + 1] + imagemPiccolo[indice + 2])/3;
            imagemPiccolo[indice] = mediaPixel;
            imagemPiccolo[indice + 1] = mediaPixel;
            imagemPiccolo[indice + 2] = mediaPixel;
        }*/
       
        // Deixar avermelhada
        for(int x = 0; x < larguraPiccolo; x++){
            unsigned int indice = (y * larguraPiccolo + x) * canaisPiccolo;
            if(imagemPiccolo[indice] > 155){
                imagemPiccolo[indice] = 255;
            }
             else {
                imagemPiccolo[indice] += 100;
            }

            if(imagemPiccolo[indice + 1] < 100){
                imagemPiccolo[indice + 1] = 0;
            }
            else {
                imagemPiccolo[indice + 1] -= 100;
            }
            
           
        }
    }

    stbi_write_png("images/piccolo_escala_cinza.png", larguraPiccolo, alturaPiccolo, canaisPiccolo, imagemPiccolo, 0);
    
    return 0;
}
