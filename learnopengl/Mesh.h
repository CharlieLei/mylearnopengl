#ifndef LEARNOPENGL_MESH_H
#define LEARNOPENGL_MESH_H

#include <glm/glm.hpp>
#include <assimp/scene.h>

#include "Shader.h"

#include <vector>
#include <string>

using namespace std;

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

struct Texture {
    unsigned int id;
    string type;
    aiString path;
};

class Mesh {
public:
    vector<Vertex> vertices;
    vector<unsigned int> indices;
    vector<Texture> textures;

    Mesh(vector<Vertex> &vertices, vector<unsigned int> &indices, vector<Texture> &textures);
    void Draw(Shader shader);

private:
    unsigned int VAO, VBO, EBO;
    void setupMesh();
};


#endif //LEARNOPENGL_MESH_H
