#ifndef KMUCS_GRAPHICS_TRANSFORM_HPP
#define KMUCS_GRAPHICS_TRANSFORM_HPP

#include <cmath>
#include "vec.hpp"
#include "mat.hpp"
#include "operator.hpp"

namespace kmuvcl
{
    namespace math
    {
#ifndef M_PI
        const float M_PI = 3.14159265358979323846;
#endif


        template <typename T>
        mat<4, 4, T> translate(T dx, T dy, T dz)
        {
            mat<4, 4, T> translateMat;
            translateMat.set_ith_row(0, vec4f(1,0,0,dx));
            translateMat.set_ith_row(1, vec4f(0,1,0,dy));
            translateMat.set_ith_row(2, vec4f(0,0,1,dz));
            translateMat.set_ith_row(3, vec4f(0,0,0,1));
            // TODO: Fill up this function properly

            return translateMat;
        }

        template <typename T>
        mat<4, 4, T> rotate(T angle, T x, T y, T z)
        {
            mat<4, 4, T> rotateMat;

            T theta = angle * M_PI / 180.0;

            T ux = x / sqrtf((x*x + y*y + z*z));
            T uy = y / sqrtf((x*x + y*y + z*z));
            T uz = z / sqrtf((x*x + y*y + z*z));

            rotateMat.set_ith_row(0, vec<4,T>(cos(theta)+ux*ux*(1-cos(theta)),ux*uy*(1-cos(theta))-uz*sin(theta),ux*uz*(1-cos(theta))+uy*sin(theta),0));
            rotateMat.set_ith_row(1, vec<4,T>(uy*ux*(1-cos(theta))+uz*sin(theta),cos(theta)+uy*uy*(1-cos(theta)),uy*uz*(1-cos(theta))-ux*sin(theta),0));
            rotateMat.set_ith_row(2, vec<4,T>(uz*ux*(1-cos(theta))-uy*sin(theta),uz*uy*(1-cos(theta))+ux*sin(theta),cos(theta)+uz*uz*(1-cos(theta)),0));
            rotateMat.set_ith_row(3, vec<4,T>(0,0,0,1));
            // TODO: Fill up this function properly

            return rotateMat;
        }

        template<typename T>
        mat<4, 4, T> scale(T sx, T sy, T sz)
        {
            mat<4, 4, T> scaleMat;
            scaleMat.set_ith_row(0, vec4f(sx,0,0,0));
            scaleMat.set_ith_row(1, vec4f(0,sy,0,0));
            scaleMat.set_ith_row(2, vec4f(0,0,sz,0));
            scaleMat.set_ith_row(3, vec4f(0,0,0,1));

            // TODO: Fill up this function properly

            return scaleMat;
        }

        template<typename T>
        mat<4, 4, T> lookAt(T eyeX, T eyeY, T eyeZ, T centerX, T centerY, T centerZ, T upX, T upY, T upZ)
        {
            mat<4, 4, T> viewMat;

            vec<3,T> z(eyeX-centerX, eyeY-centerY, eyeZ-centerZ);
            z(0) = z(0)/ sqrt(z(0)*z(0) + z(1)*z(1) + z(2)*z(2)) ;
            z(1) = z(1)/ sqrt(z(0)*z(0) + z(1)*z(1) + z(2)*z(2)) ;
            z(2) = z(2)/ sqrt(z(0)*z(0) + z(1)*z(1) + z(2)*z(2)) ;
            vec<3,T> y(upX, upY, upZ);
            vec<3,T> x = kmuvcl::math::cross(y,z);
            x(0) = x(0)/ sqrt(x(0)*x(0) + x(1)*x(1) + x(2)*x(2)) ;
            x(1) = x(1)/ sqrt(x(0)*x(0) + x(1)*x(1) + x(2)*x(2)) ;
            x(2) = x(2)/ sqrt(x(0)*x(0) + x(1)*x(1) + x(2)*x(2)) ;
            y = kmuvcl::math::cross(z,x);

            viewMat(0,0) = x(0); viewMat(1,0) = y(0); viewMat(2,0) = z(0);
            viewMat(0,1) = x(1); viewMat(1,1) = y(1); viewMat(2,1) = z(1);
            viewMat(0,2) = x(2); viewMat(1,2) = y(2); viewMat(2,2) = z(2);
            viewMat.set_ith_column(3,vec4f(eyeX, eyeY, eyeZ, 1));

            // TODO: Fill up this function properly

            return viewMat;
        }

        template<typename T>
        mat<4, 4, T> ortho(T left, T right, T bottom, T top, T nearVal, T farVal)
        {
            mat<4, 4, T> orthoMat;
            orthoMat.set_ith_row(0, vec<4,T>(2/(right-left), 0, 0, -(right+left)/(right-left)));
            orthoMat.set_ith_row(1, vec<4,T>(0, 2/(top-bottom),0,-(top+bottom)/(top-bottom)));
            orthoMat.set_ith_row(2, vec<4,T>(0,0,-2/(farVal-nearVal),-(farVal+nearVal)/(farVal-nearVal)));
            orthoMat.set_ith_row(3, vec<4,T>(0,0,0,1));
            // TODO: Fill up this function properly

            return orthoMat;
        }

        template<typename T>
        mat<4, 4, T> frustum(T left, T right, T bottom, T top, T nearVal, T farVal)
        {
           mat<4, 4, T> frustumMat;
           frustumMat.set_ith_row(0,vec<4,T>(2*nearVal/(right-left), 0, (right+left)/(right-left), 0));

           frustumMat.set_ith_row(1,vec<4,T>(0, 2*nearVal/(top-bottom), (top+bottom) / (top-bottom), 0));

           frustumMat.set_ith_row(2,vec<4,T>(0,0,-(farVal+nearVal)/(farVal-nearVal), -2*farVal*nearVal / (farVal-nearVal)));

           frustumMat.set_ith_row(3,vec<4,T>(0,0,-1,0));
           // TODO: Fill up this function properly

           return frustumMat;
        }

        template<typename T>
        mat<4, 4, T> perspective(T fovy, T aspect, T zNear, T zFar)
        {
          T  right, top;

          top = zNear * tanf(fovy*M_PI / 360.0);
          right = top * aspect;
          // TODO: Fill up this function properly

          return frustum(-right, right, -top, top, zNear, zFar);
        }
    }
}
#endif
