#pragma once

#include "check_gl.hpp"
#include <glm/glm.hpp>
#include <vector>
#include <string>

struct DrawableOBJ {
    check_gl::GLVertexArray vao;
    check_gl::GLBuffer vbo;
    check_gl::GLBuffer ebo;
    std::size_t numElements;

    void draw();
};

struct OBJ {
    struct Vertex {
        glm::vec3 position;
        glm::vec3 normal;
    };
    std::vector<Vertex> vertices;
    std::vector<glm::uvec3> faces;

    void load_obj(std::string path);
    void auto_normal();
    [[nodiscard]] DrawableOBJ draw_obj();
};
