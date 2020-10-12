//
// Created by 01 on 2020/10/11.
//

#ifndef LEARNOPENGL_MODEL_H
#define LEARNOPENGL_MODEL_H

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Shader.h"
#include "Mesh.h"

#include <vector>
#include <string>

using namespace std;

class Model {
public:
    Model(const char * path);
    void Draw(Shader shader);
private:
    vector<Mesh> meshes;
    string directory;

    void loadModel(string &path);
    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);
    vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, string typeName);
};


#endif //LEARNOPENGL_MODEL_H
