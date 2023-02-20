/**
 *
 * @file    Half_circle.h
 * @author  METAYER SLOANE
 * @date    Decembre 2021
 * @version 1.0.1
 * @brief   Représente un demi-cercle
 *
 **/

#ifndef S102_HALF_CIRCLE_H
#define S102_HALF_CIRCLE_H

#include "mingl/shape/shape.h"

#include "mingl/transition/itransitionable.h"

namespace half_circle
{
/**
 * @class Half_Circle
 * @brief Classe représentant un demi-cercle
 */
    class Half_Circle : public nsShape::Shape, public nsTransition::ITransitionable
    {
    public:
        /**
         * @brief TransitionIds : Liste de toutes les transitions que cet élément peut exécuter
         */
        enum TransitionIds {
            TRANSITION_FILL_COLOR_RGB, /**< Transition pour la couleur de remplissage */
            TRANSITION_FILL_COLOR_ALPHA, /**< Transition pour la transparence de remplissage */
            TRANSITION_BORDER_COLOR_RGB, /**< Transition pour la couleur de bord */
            TRANSITION_BORDER_COLOR_ALPHA, /**< Transition pour la transparence de bord */
            TRANSITION_POSITION, /**< Transition pour la position */
            TRANSITION_RADIUS, /**< Transition pour le rayon */
        };

        /**
         * @brief Constructeur pour la classe Half_Circle
         * @param[in] position : Position du centre
         * @param[in] radius : Rayon du demi-cercle
         * @param[in] height: Hauteur du demi-cercle
         * @param[in] direction : Direction du demi-cercle
         * @param[in] fillColor : Couleur de remplissage
         * @param[in] borderColor : Couleur de bord
         * @fn Half_Circle(const nsGraphics::Vec2D& position, const unsigned& radius,const unsigned &height, const char &direction, const nsGraphics::RGBAcolor& fillColor, const nsGraphics::RGBAcolor& borderColor = nsGraphics::KTransparent);
         */
        Half_Circle(const nsGraphics::Vec2D& position, const unsigned& radius,const unsigned &height, const char &direction, const nsGraphics::RGBAcolor& fillColor, const nsGraphics::RGBAcolor& borderColor = nsGraphics::KTransparent);

        /**
         * @brief Destructeur virtuel pour la classe Half_Circle
         * @fn virtual ~Half_Circle() override = default;
         */
        virtual ~Half_Circle() override = default;

        virtual void draw(MinGL& window) const override;

        virtual void getValues(const int &id, std::vector<float> &values) override;
        virtual void setValues(const int &id, const std::vector<float> &values) override;

        /**
         * @brief Opérateur de décalage
         * @param[in] position : Position a additionner
         * @fn Half_Circle operator+(const nsGraphics::Vec2D& position) const
         */
        Half_Circle operator+(const nsGraphics::Vec2D& getPosition) const;

        /**
         * @brief Opérateur de réduction
         * @param[in] f : Nombre avec lequel multiplier la position actuelle
         * @fn Half_Circle operator*(const float& f) const
         */
        Half_Circle operator*(const float& f) const;

        /**
         * @brief Récupère la position du demi-cercle
         * @fn const nsGraphics::Vec2D& getPosition() const;
         */
        const nsGraphics::Vec2D& getPosition() const;

        /**
         * @brief Définit la nouvelle position du demi-cercle
         * @param[in] position : Nouvelle position
         * @fn void setPosition(const nsGraphics::Vec2D &position);
         */
        void setPosition(const nsGraphics::Vec2D &position);

        /**
         * @brief Récupère le rayon du cercle
         * @fn unsigned getRadius() const;
         */
        unsigned getRadius() const;

        /**
         * @brief Définit le nouveau rayon du demi-cercle
         * @param[in] radius : Nouveau rayon
         * @fn setRadius(const unsigned &radius);
         */
        void setRadius(const unsigned &radius);

    private:
        /**
         * @brief m_position : Position du centre
         */
        nsGraphics::Vec2D m_position;

        /**
         * @brief m_radius : Rayon du demi-cercle
         * @brief m_height : Hauteur du demi-cercle
         * @brief m_direction : Direction du demi-cercle
         */
        unsigned m_radius;
        unsigned m_height;
        char m_direction;
    }; // class Half_Circle
} // namespace half_circle

#endif // S102_HALF_CIRCLE_H
