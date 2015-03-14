/**
 * @author    Jani Haippo
 * @version   03.2015
 **/
 
 #ifndef STREETRACER_IWINDOW_H
 #define STREETRACER_IWINDOW_H
 
 #include "../core/base.inc"
 
 namespace SR
 {
    class IWindow
    {
      public:
        virtual void Create(std::string& name, int width, int height)=0;
        virtual void Resize(int width, int height)=0;
      protected:
        int   m_width;
        int   m_height;
    };
 }
 #endif