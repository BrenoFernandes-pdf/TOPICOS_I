#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "Headers/stb_image.h"
#include "Headers/stb_image_write.h"
#include <iostream>

int main(){
    int largura, altura, canais;
    unsigned char* imagem = stbi_load("images/falso_vermelho.jpg", &largura, &altura, &canais, 0);
    if(!imagem){
        std::cout << "oh, não achei essa imagem não viu!" << std::endl;
        return -1;
    }
    std::cout << largura << "-" << altura << "-" << canais << std::endl;
    for(int y = 0; y < altura; y++){
        for(int x = 0; x < largura; x++){
            unsigned int indice = (y*largura + x) * canais;
            unsigned char *r, *g, *b;
            r = &imagem[indice];
            g = &imagem[indice + 1];
            b = &imagem[indice + 2];
            /*if(*r != 255  || *g != 0 || *b != 0){
                std::cout << (int)*r << "-" << (int)*g << "-" << (int)*b << std::endl;
            }*/

        
            if(x == (largura/2) || y == (altura/2)){
                *r = 100;
                *g = 100;
                *b = 100;
            }

            if(x == y){
                *r = 100;
                *g = 100;
                *b = 100;
            }
        }
    }
    stbi_write_png("images/falso_vermelho.jpg", largura, altura, canais, imagem, 0);
    
    return 0;
}
