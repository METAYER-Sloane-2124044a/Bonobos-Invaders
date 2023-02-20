/**
 *
 * @file    arc_circle.cpp
 * @author  METAYER SLOANE
 * @date    Decembre 2021
 * @version 1.0.1
 * @brief   Représente un arc de cercle
 *
 **/

#include "game/graphic/arc_circle.h"

nsShape::Arc_Circle::Arc_Circle(const nsGraphics::Vec2D &position, const unsigned &radius,const unsigned &height, const char &direction,const nsGraphics::RGBAcolor &fillColor, const nsGraphics::RGBAcolor &borderColor)
        : Shape(fillColor, borderColor)
        , m_position(position)
        , m_radius(radius)
        , m_height(height)
        , m_direction(direction)
{} // Arc_Circle()

void nsShape::Arc_Circle::draw(MinGL& window) const
{
    UNUSED(window);

    // Source: https://gist.github.com/linusthe3rd/803118

    int i;
    int lineAmount = 28; // Nombre de lines a dessiner

    // On règle la couleur du cercle
    const nsGraphics::RGBAcolor inColor = getFillColor();
    glColor4ub(inColor.getRed(), inColor.getGreen(), inColor.getBlue(), inColor.getAlpha()); // Couleur du cercle

    GLfloat twicePi = 2.0f * M_PI;

    glBegin(GL_LINE_STRIP);


    if (m_direction=='b') {
        //Arc de cercle dirigé vers le bas
        for (i = 0; i <= lineAmount / 2; i++) {
            glVertex2f(m_position.getX() + (m_radius * cos(i * twicePi / lineAmount)),
                       m_position.getY() + (m_height * sin(i * twicePi / lineAmount)));
        }
    }
    else if (m_direction=='r'){
        //Arc de cercle dirigé vers la droite
        for (i = 0; i <= lineAmount / 2; i++) {
            glVertex2f(m_position.getX() + (m_height* sin(i * twicePi / lineAmount)),
                       m_position.getY() + (m_radius * cos(i * twicePi / lineAmount)));
        }
    }
    glEnd();
} // draw()

void nsShape::Arc_Circle::getValues(const int &id, std::vector<float> &values)
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

void nsShape::Arc_Circle::setValues(const int &id, const std::vector<float> &values)
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