# Detecção de Faixa de Pedestres com Processamento Digital de Imagens

## Componentes:
- Ítalo Maciel

Este projeto implementa um sistema para identificação automática de faixas de pedestres utilizando técnicas clássicas de Processamento Digital de Imagens (PDI) com a biblioteca OpenCV em linguagem C.

O sistema suporta três modos de execução:
- Vídeo (webcam ou arquivo de vídeo)
- Imagem única
- Batch de imagens (processamento em lote)

Além disso, o projeto utiliza a Transformada de Hough para detecção robusta de linhas horizontais, característica fundamental das faixas de pedestres.

---

## 🧰 Pré-requisitos

- Sistema operacional Linux
- GCC (ou Clang)
- OpenCV (versão 3.x ou superior)
- pkg-config

### Verificar OpenCV instalado
```
bash
pkg-config --modversion opencv 
```

### Instruções
- Compilação:
Na raiz do projeto executar o seguinte comando
``` 
make 
```

- Execução:
```
./crosswalk
```
