#include "Camera.h"

glm::mat4 myLookAt(glm::vec3 eyePos, glm::vec3 target, glm::vec3 worldUp)
{
    glm::vec3 front = glm::normalize(eyePos - target);
    glm::vec3 right = glm::normalize(glm::cross(worldUp, front));
    glm::vec3 up    = glm::normalize(glm::cross(right, front));
    glm::mat4 rotation(1.0f);
    rotation[0][0] = right.x;
    rotation[1][0] = right.y;
    rotation[2][0] = right.z;
    rotation[0][1] = up.x;
    rotation[1][1] = up.y;
    rotation[2][1] = up.z;
    rotation[0][2] = front.x;
    rotation[1][2] = front.y;
    rotation[2][2] = front.z;

    glm::mat4 translation(1.0f);
    translation[3][0] = -eyePos.x;
    translation[3][1] = -eyePos.y;
    translation[3][2] = -eyePos.z;

    return rotation * translation;
}

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
        : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM) {
    Position = position;
    WorldUp = up;
    Yaw = yaw;
    Pitch = pitch;
    updateCameraVectors();
}

Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch)
        : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM) {
    Position = glm::vec3(posX, posY, posZ);
    WorldUp = glm::vec3(upX, upY, upZ);
    Yaw = yaw;
    Pitch = pitch;
    updateCameraVectors();
}

glm::mat4 Camera::GetViewMatrix()
{
//    return glm::lookAt(Position, Position + Front, Up);
    return myLookAt(Position, Position + Front, WorldUp);
}

void Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime)
{
    float velocity = MovementSpeed * deltaTime;
    if      (direction == FORWARD)  Position += velocity * Front;
    else if (direction == BACKWARD) Position -= velocity * Front;
    else if (direction == LEFT)     Position -= velocity * Right;
    else if (direction == RIGHT)    Position += velocity * Right;

    Position.y = 0.0f;
}

void Camera::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch)
{
    xoffset *= MouseSensitivity;
    yoffset *= MouseSensitivity;

    Yaw   += xoffset;
    Pitch += yoffset;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (constrainPitch)
    {
        if      (Pitch > 89.0f)  Pitch = 89.0f;
        else if (Pitch < -89.0f) Pitch = -89.0f;
    }

    updateCameraVectors();
}

void Camera::ProcessMouseScroll(float yoffset)
{
    Zoom -= yoffset;
    if      (Zoom < 1.0f)  Zoom = 1.0f;
    else if (Zoom > 45.0f) Zoom = 45.0f;
}

void Camera::updateCameraVectors()
{
    glm::vec3 newFront;
    newFront.x = cos(glm::radians(Pitch)) * cos(glm::radians(Yaw));
    newFront.y = sin(glm::radians(Pitch));
    newFront.z = cos(glm::radians(Pitch)) * sin(glm::radians(Yaw));
    Front = newFront;
    Right = glm::normalize( glm::cross(Front, WorldUp) );
    Up    = glm::normalize( glm::cross(Right, Front));
}