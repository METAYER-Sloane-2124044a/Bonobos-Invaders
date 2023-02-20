/**
 *
 * @file    Half_circle.cpp
 * @author  METAYER SLOANE
 * @date    Decembre 2021
 * @version 1.0.1
 * @brief   Représente un demi-cercle
 *
 **/

#include <cmath>
#include "game/graphic/half_circle.h"
#include "mingl/macros.h"

/**
 *
 * @param[in] position : Position du centre
 * @param[in] radius : Rayon du demi-cercle
 * @param[in] height: Hauteur du demi-cercle
 * @param[in] direction : Direction du demi-cercle
 * @param[in] fillColor : Couleur de remplissage
 * @param[in] borderColor : Couleur de bord
 * @fn Half_Circle(const nsGraphics::Vec2D& position, const unsigned& radius,const unsigned &height, const char &direction, const nsGraphics::RGBAcolor& fillColor, const nsGraphics::RGBAcolor& borderColor = nsGraphics::KTransparent);
 */
half_circle::Half_Circle::Half_Circle(const nsGraphics::Vec2D &position, const unsigned &radius,const unsigned &height, const char &direction, const nsGraphics::RGBAcolor &fillColor, const nsGraphics::RGBAcolor &borderColor)
        : Shape(fillColor, borderColor)
        , m_position(position)
        , m_radius(radius)
        , m_height(height)
        , m_direction(direction)
{} // Half_Circle()

void half_circle::Half_Circle::draw(MinGL& window) const
{
    UNUSED(window);

    // Source: https://gist.github.com/linusthe3rd/803118

    int i;
    int triangleAmount = 30; // Nombre de triangles a dessiner

    // Réglage de la couleur du demi-cercle
    const nsGraphics::RGBAcolor inColor = getFillColor();
    glColor4ub(inColor.getRed(), inColor.getGreen(), inColor.getBlue(), inColor.getAlpha()); // Couleur du cercle

    GLfloat twicePi = 2.0f * M_PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(m_position.getX(), m_position.getY()); // Centre du demi-cercle

    //Demi-cercle dirigé vers le haut
    if (m_direction =='t') {
        for (i = 0; i <= triangleAmount / 2; i++) {
            glVertex2f(m_position.getX() + (m_radius * cos(i * twicePi / triangleAmount)),
                       m_position.getY() - (m_height * sin(i * twicePi / triangleAmount)));
        }
    }
    //Demi-cercle dirigé vers le bas
    else if (m_direction=='b'){
        for (i = 0; i <= triangleAmount / 2; i++) {
            glVertex2f(m_position.getX() + (m_radius * cos(i * twicePi / triangleAmount)),
                       m_position.getY() + (m_height * sin(i * twicePi / triangleAmount)));
        }
    }
    //Demi-cercle dirigé vers la droite
    else if(m_direction=='r'){
        for (i = 0; i <= triangleAmount / 2; i++) {
            glVertex2f(m_position.getX() + (m_height * sin(i * twicePi / triangleAmount)),
                       m_position.getY() + (m_radius * cos(i * twicePi / triangleAmount)));
        }
    }
    //Demi-cercle dirigé vers la gauche
    else if(m_direction=='l'){
        for (i = 0; i <= triangleAmount / 2; i++) {
            glVertex2f(m_position.getX() - (m_height * sin(i * twicePi / triangleAmount)),
                       m_position.getY() + (m_radius * cos(i * twicePi / triangleAmount)));
        }
    }
    glEnd();
} // draw()

void half_circle::Half_Circle::getValues(const int &id, std::vector<float> &values)
{
    switch (id) {
        case TRANSITION_FILL_COLOR_RGB:
            values[0] = m_fillColor.getRed();
            values[1] = m_fillColor.getGreen();
            values[2] = m_fillColor.getBlue();

            break;

        case TRANSITION_FILL_COLOR_ALPHA:
            values[0] = m_fillColor.getAlpha();

            break;

        case TRANSITION_BORDER_COLOR_RGB:
            values[0] = m_borderColor.getRed();
            values[1] = m_borderColor.getGreen();
            values[2] = m_borderColor.getBlue();

            break;

        case TRANSITION_BORDER_COLOR_ALPHA:
            values[0] = m_borderColor.getAlpha();

            break;

        case TRANSITION_POSITION:
            values[0] = m_position.getX();
            values[1] = m_position.getY();

            break;

        case TRANSITION_RADIUS:
            values[0] = m_radius;

            break;
    }
} // getValues()

void half_circle::Half_Circle::setValues(const int &id, const std::vector<float> &values)
{
    switch (id) {
        case TRANSITION_FILL_COLOR_RGB:
            m_fillColor.setRed(values[0]);
            m_fillColor.setGreen(values[1]);
            m_fillColor.setBlue(values[2]);

            break;

        case TRANSITION_FILL_COLOR_ALPHA:
            m_fillColor.setAlpha(values[0]);

            break;

        case TRANSITION_BORDER_COLOR_RGB:
            m_borderColor.setRed(values[0]);
            m_borderColor.setGreen(values[1]);
            m_borderColor.setBlue(values[2]);

            break;

        case TRANSITION_BORDER_COLOR_ALPHA:
            m_borderColor.setAlpha(values[0]);

            break;

        case TRANSITION_POSITION:
            m_position.setX(values[0]);
            m_position.setY(values[1]);

            break;

        case TRANSITION_RADIUS:
            m_radius = values[0];

            break;
    }
} // setValues()
