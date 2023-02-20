/**
 *
 * @file    arc_circle.h
 * @author  METAYER SLOANE
 * @date    Decembre 2021
 * @version 1.0.1
 * @brief   Représente un arc de cercle
 *
 **/

#ifndef S102_ARC_CIRCLE_H
#define S102_ARC_CIRCLE_H

#include "mingl/shape/shape.h"
#include <cmath>
#include "mingl/macros.h"

#include "mingl/transition/itransitionable.h"

namespace nsShape
{

/**
 * @class Arc_Circle
 * @brief Classe représentant un arc de cercle
 */
    class Arc_Circle : public Shape, public nsTransition::ITransitionable
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
         * @brief Constructeur pour la classe Arc_Circle
         * @param[in] firstPosition : Position du centre
         * @param[in] radius : Rayon de l'arc de cercle
         * @param[in] height : Hauteur de l'arc de cercle
         * @param[in] direction : Direction de l'arc de cercle
         * @param[in] fillColor : Couleur de remplissage
         * @param[in] borderColor : Couleur de bord
         * @fn Arc_Circle(const nsGraphics::Vec2D& position, const unsigned& radius, const unsigned &height, const char &direction, const nsGraphics::RGBAcolor& fillColor, const nsGraphics::RGBAcolor& borderColor = nsGraphics::KTransparent);
         */
        Arc_Circle(const nsGraphics::Vec2D& position, const unsigned& radius,const unsigned &height,const char &direction, const nsGraphics::RGBAcolor& fillColor, const nsGraphics::RGBAcolor& borderColor = nsGraphics::KTransparent);

        /**
         * @brief Destructeur virtuel pour la classe Arc_Circle
         * @fn virtual ~Arc_Circle() override = default;
         */
        virtual ~Arc_Circle() override = default;

        virtual void draw(MinGL& window) const override;

        virtual void getValues(const int &id, std::vector<float> &values) override;
        virtual void setValues(const int &id, const std::vector<float> &values) override;

        /**
         * @brief Opérateur de décalage
         * @param[in] position : Position a additionner
         * @fn Arc_Circle operator+(const nsGraphics::Vec2D& position) const;
         */
        Arc_Circle operator+(const nsGraphics::Vec2D& getPosition) const;

        /**
         * @brief Opérateur de réduction
         * @param[in] f : Nombre avec lequel multiplier la position actuelle
         * @fn Arc_Circle operator*(const float& f) const
         */
        Arc_Circle operator*(const float& f) const;

        /**
         * @brief Récupère la position de l'arc de cercle
         * @fn const nsGraphics::Vec2D& getPosition() const;
         */
        const nsGraphics::Vec2D& getPosition() const;

        /**
         * @brief Définit la nouvelle position de l'arc de cercle
         * @param[in] position : Nouvelle position
         * @fn setPosition(const nsGraphics::Vec2D &position);
         */
        void setPosition(const nsGraphics::Vec2D &position);

        /**
         * @brief Récupère le rayon de l'arc de cercle
         * @fn unsigned getRadius() const;
         */
        unsigned getRadius() const;

        /**
         * @brief Définit le nouveau rayon de l'arc de cercle
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
         * @brief m_radius : Rayon du cercle
         */
        unsigned m_radius;
        char m_direction;
        unsigned m_height;
    }; // class Arc_Circle

} // namespace nsShape

#endif // S102_ARC_CIRCLE_H