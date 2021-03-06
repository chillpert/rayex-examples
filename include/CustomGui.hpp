#ifndef CUSTOM_GUI_HPP
#define CUSTOM_GUI_HPP

#include "Example.hpp"
#include "Keys.hpp"

class CustomGui : public rx::Gui
{
public:
  CustomGui( rx::Rayex* renderer ) :
    _renderer( renderer ) {}

private:
  ImFont* _font = nullptr;

  void configure( ) override
  {
    rx::Gui::configure( );

    ImGuiIO& io      = ImGui::GetIO( );
    std::string path = std::string( _renderer->settings( ).getAssetsPath( ) ) + "DroidSans.ttf";
    _font            = io.Fonts->AddFontFromFileTTF( path.c_str( ), 15.0f );

    ImGui::StyleColorsDark( );
    ImGuiStyle& style = ImGui::GetStyle( );

    style.WindowBorderSize  = 0.0f;
    style.WindowBorderSize  = 1.0f;
    style.WindowRounding    = 0.0f;
    style.FrameRounding     = 4.0f;
    style.GrabRounding      = 4.0f;
    style.PopupRounding     = 4.0f;
    style.ScrollbarRounding = 4.0f;

    ImVec4* colors                        = ImGui::GetStyle( ).Colors;
    colors[ImGuiCol_Text]                 = ImVec4( 1.00f, 1.00f, 1.00f, 1.00f );
    colors[ImGuiCol_TextDisabled]         = ImVec4( 0.50f, 0.50f, 0.50f, 1.00f );
    colors[ImGuiCol_WindowBg]             = ImVec4( 0.18f, 0.18f, 0.18f, 0.61f );
    colors[ImGuiCol_ChildBg]              = ImVec4( 0.18f, 0.18f, 0.18f, 1.00f );
    colors[ImGuiCol_PopupBg]              = ImVec4( 0.18f, 0.18f, 0.18f, 1.00f );
    colors[ImGuiCol_Border]               = ImVec4( 0.22f, 0.22f, 0.22f, 1.00f );
    colors[ImGuiCol_BorderShadow]         = ImVec4( 0.22f, 0.22f, 0.22f, 1.00f );
    colors[ImGuiCol_FrameBg]              = ImVec4( 0.26f, 0.26f, 0.26f, 1.00f );
    colors[ImGuiCol_FrameBgHovered]       = ImVec4( 0.31f, 0.31f, 0.31f, 1.00f );
    colors[ImGuiCol_FrameBgActive]        = ImVec4( 0.41f, 0.41f, 0.41f, 0.31f );
    colors[ImGuiCol_TitleBg]              = ImVec4( 0.26f, 0.26f, 0.26f, 1.00f );
    colors[ImGuiCol_TitleBgActive]        = ImVec4( 0.26f, 0.26f, 0.26f, 1.00f );
    colors[ImGuiCol_TitleBgCollapsed]     = ImVec4( 0.26f, 0.26f, 0.26f, 1.00f );
    colors[ImGuiCol_MenuBarBg]            = ImVec4( 0.20f, 0.20f, 0.20f, 1.00f );
    colors[ImGuiCol_ScrollbarBg]          = ImVec4( 0.21f, 0.21f, 0.21f, 1.00f );
    colors[ImGuiCol_ScrollbarGrab]        = ImVec4( 0.31f, 0.31f, 0.31f, 1.00f );
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4( 0.41f, 0.41f, 0.41f, 1.00f );
    colors[ImGuiCol_ScrollbarGrabActive]  = ImVec4( 0.51f, 0.51f, 0.51f, 1.00f );
    colors[ImGuiCol_CheckMark]            = ImVec4( 1.00f, 1.00f, 1.00f, 1.00f );
    colors[ImGuiCol_SliderGrab]           = ImVec4( 0.39f, 0.39f, 0.39f, 1.00f );
    colors[ImGuiCol_SliderGrabActive]     = ImVec4( 0.39f, 0.39f, 0.39f, 1.00f );
    colors[ImGuiCol_Button]               = ImVec4( 0.26f, 0.26f, 0.26f, 1.00f );
    colors[ImGuiCol_ButtonHovered]        = ImVec4( 0.39f, 0.39f, 0.39f, 1.00f );
    colors[ImGuiCol_ButtonActive]         = ImVec4( 0.39f, 0.39f, 0.39f, 1.00f );
    colors[ImGuiCol_Header]               = ImVec4( 0.26f, 0.26f, 0.26f, 1.00f );
    colors[ImGuiCol_HeaderHovered]        = ImVec4( 0.39f, 0.39f, 0.39f, 1.00f );
    colors[ImGuiCol_HeaderActive]         = ImVec4( 0.20f, 0.20f, 0.20f, 1.00f );
    colors[ImGuiCol_Separator]            = ImVec4( 0.20f, 0.20f, 0.20f, 1.00f );
    colors[ImGuiCol_SeparatorHovered]     = ImVec4( 0.31f, 0.31f, 0.31f, 1.00f );
    colors[ImGuiCol_SeparatorActive]      = ImVec4( 0.31f, 0.31f, 0.31f, 1.00f );
    colors[ImGuiCol_ResizeGrip]           = ImVec4( 1.00f, 1.00f, 1.00f, 0.59f );
    colors[ImGuiCol_ResizeGripHovered]    = ImVec4( 1.00f, 1.00f, 1.00f, 1.00f );
    colors[ImGuiCol_ResizeGripActive]     = ImVec4( 1.00f, 1.00f, 1.00f, 1.00f );
    colors[ImGuiCol_Tab]                  = ImVec4( 0.24f, 0.24f, 0.24f, 1.00f );
    colors[ImGuiCol_TabHovered]           = ImVec4( 0.27f, 0.27f, 0.27f, 1.00f );
    colors[ImGuiCol_TabActive]            = ImVec4( 0.36f, 0.35f, 0.35f, 1.00f );
    colors[ImGuiCol_TabUnfocused]         = ImVec4( 0.23f, 0.23f, 0.23f, 1.00f );
    colors[ImGuiCol_TabUnfocusedActive]   = ImVec4( 0.20f, 0.20f, 0.20f, 1.00f );
    //colors[ImGuiCol_DockingPreview]        = ImVec4( 0.59f, 0.59f, 0.59f, 1.00f );
    //colors[ImGuiCol_DockingEmptyBg]        = ImVec4( 0.00f, 0.00f, 0.00f, 0.00f );
    colors[ImGuiCol_PlotLines]             = ImVec4( 0.59f, 0.59f, 0.59f, 1.00f );
    colors[ImGuiCol_PlotLinesHovered]      = ImVec4( 0.80f, 0.35f, 0.02f, 1.00f );
    colors[ImGuiCol_PlotHistogram]         = ImVec4( 0.90f, 0.70f, 0.00f, 1.00f );
    colors[ImGuiCol_PlotHistogramHovered]  = ImVec4( 1.00f, 0.60f, 0.00f, 1.00f );
    colors[ImGuiCol_TextSelectedBg]        = ImVec4( 0.26f, 0.59f, 0.98f, 0.35f );
    colors[ImGuiCol_DragDropTarget]        = ImVec4( 1.00f, 1.00f, 0.00f, 0.90f );
    colors[ImGuiCol_NavHighlight]          = ImVec4( 0.26f, 0.59f, 0.98f, 1.00f );
    colors[ImGuiCol_NavWindowingHighlight] = ImVec4( 1.00f, 1.00f, 1.00f, 0.70f );
    colors[ImGuiCol_NavWindowingDimBg]     = ImVec4( 0.80f, 0.80f, 0.80f, 0.20f );
    colors[ImGuiCol_ModalWindowDimBg]      = ImVec4( 0.80f, 0.80f, 0.80f, 0.35f );
  }

  void render( ) override
  {
    if ( _font != nullptr )
    {
      ImGui::PushFont( _font );
      ImGui::PopFont( );
    }

    static bool showDemoWindow = false;
    if ( showDemoWindow )
    {
      ImGui::ShowDemoWindow( );
    }

    static auto flags = ImGuiTreeNodeFlags_DefaultOpen;

    if ( ImGui::Begin( "Settings" ) )
    {
      if ( ImGui::CollapsingHeader( "Scene", flags ) )
      {
        if ( ImGui::Button( "Clear instances" ) )
        {
          _renderer->scene( ).clearGeometryInstances( );
        }

        ImGui::SameLine( );

        if ( ImGui::Button( "Clear geometry" ) )
        {
          _renderer->scene( ).clearGeometries( );
        }

        if ( ImGui::Button( "Pop geometry instance" ) )
        {
          _renderer->scene( ).popGeometryInstance( );
        }

        ImGui::SameLine( );

        if ( ImGui::Button( "Pop geometry" ) )
        {
          _renderer->scene( ).popGeometry( );
        }

        if ( ImGui::Button( "Set environment map" ) )
        {
          _renderer->scene( ).setEnvironmentMap( "models/skybox/cubemap_yokohama_rgba.ktx" );
        }

        ImGui::SameLine( );

        if ( ImGui::Button( "Remove environment map" ) )
        {
          _renderer->scene( ).removeEnvironmentMap( );
        }

        const char* items[]     = { "bunny", "vulkan", "venus", "dragon", "teapot", "voyager", "lucy" };
        static int item_current = 0;
        ImGui::SetNextItemWidth( 200.0F );
        ImGui::Combo( "##model", &item_current, items, IM_ARRAYSIZE( items ) );

        static int quantity = 1;
        ImGui::SetNextItemWidth( 100.0F );
        ImGui::InputInt( "##Quantity", &quantity );

        ImGui::SameLine( );

        static bool random = true;
        ImGui::Checkbox( "Random Position", &random );

        ImGui::SameLine( );

        if ( ImGui::Button( "Spawn Model" ) )
        {
          std::string temp( items[item_current] );
          std::string temp2 = "models/" + temp + ".obj";

          for ( int i = 0; i < quantity; ++i )
          {
            auto transform = random ? glm::translate( glm::mat4( 1.0F ), getRandomUniquePosition( -25.0F, 25.0F ) ) : glm::mat4( 1.0F );
            addModel( _renderer, temp2.c_str( ), transform );
          }
        }

        ImGui::NewLine( );
      }

      if ( ImGui::CollapsingHeader( "Resource Monitor", flags ) )
      {
        const size_t maxFrames = 10000;
        static std::array<float, maxFrames> frameTimes;

        static size_t counter = 0;
        counter               = counter % maxFrames;

        float dt = rx::Time::getDeltaTime( );
        if ( dt > 0.001f )
        {
          if ( counter >= maxFrames - 1 )
          {
            std::fill( frameTimes.begin( ), frameTimes.end( ), 0.0f );
          }

          frameTimes[counter] = dt;
          ++counter;
        }

        ImGui::SetNextItemWidth( -1 );
        ImGui::PlotLines( "Frametimes", frameTimes.data( ), maxFrames, 0, "Frametime", 0.0F, 0.12F, ImVec2( 0.0F, 120.0F ) );

        std::string fpsDisplay = "FPS: " + std::to_string( rx::Time::getFramesPerSecond( ) );
        ImGui::Text( fpsDisplay.c_str( ) );

        static int benchmark_length = 60;
        ImGui::InputInt( "Length", &benchmark_length );
        if ( benchmark_length < 5 )
        {
          benchmark_length = 5;
        }

        ImGui::SameLine( );

        if ( ImGui::Button( "Start" ) )
        {
          rx::Time::startBenchmark( static_cast<size_t>( benchmark_length ) );
        }

#ifdef RX_VARIANCE_CALCULATOR
        static float variance        = 0.0F;
        static bool estimateVariance = false;

        static int varLength = 1;
        ImGui::SetNextItemWidth( 100.0F );
        ImGui::InputInt( "##LengthVar", &varLength, 1.0F, 60.0F );

        ImGui::SameLine( );

        static float endTime   = 0.0F;
        static bool startedVar = false;
        if ( ImGui::Button( "Estimate Variance" ) )
        {
          endTime = rx::Time::getTime( ) + static_cast<float>( varLength );

          _renderer->settings( ).updateVariance( true );
          startedVar = true;
        }

        if ( startedVar && rx::Time::getTime( ) >= endTime )
        {
          _renderer->settings( ).updateVariance( false );
          variance   = _renderer->settings( ).getVariance( );
          endTime    = 0.0F;
          startedVar = false;
        }

        ImGui::SameLine( );

        char var[64];
        sprintf( var, "%f", variance );
        ImGui::Text( var );

#endif
        ImGui::NewLine( );
      }

      if ( ImGui::CollapsingHeader( "Settings", flags ) )
      {
        ImGui::Checkbox( "Show ImGui demo window", &showDemoWindow );

        bool accumulateFrames = _renderer->settings( ).isAccumulatingFrames( );
        ImGui::Checkbox( "Accumulate frames", &accumulateFrames );
        _renderer->settings( ).setAccumulatingFrames( accumulateFrames );

        auto clearColor = _renderer->settings( ).getClearColor( );
        if ( ImGui::ColorEdit4( "##AmbientColor", &clearColor[0] ) )
        {
          _renderer->settings( ).setClearColor( clearColor );
        }

        bool russianRoulette = _renderer->settings( ).getRussianRoulette( );
        if ( ImGui::Checkbox( "##Russian Roulette 2", &russianRoulette ) )
        {
          _renderer->settings( ).setAccumulatingFrames( false );
        }
        _renderer->settings( ).setRussianRoulette( russianRoulette );

        ImGui::SameLine( );

        static int minBounces = static_cast<int>( _renderer->settings( ).getRussianRouletteMinBounces( ) );
        ImGui::SetNextItemWidth( 100.0F );
        if ( ImGui::InputInt( "Russian Roulette", &minBounces ) )
        {
          _renderer->settings( ).setRussianRouletteMinBounces( static_cast<uint32_t>( minBounces ) );
          _renderer->settings( ).setAccumulatingFrames( false );
        }

        bool nee = _renderer->settings( ).getNextEventEstimation( );
        if ( ImGui::Checkbox( "##Next Event Estimation 2", &nee ) )
        {
          _renderer->settings( ).setAccumulatingFrames( false );
        }
        _renderer->settings( ).setNextEventEstimation( nee );

        ImGui::SameLine( );

        static int neeMinBounces = static_cast<int>( _renderer->settings( ).getNextEventEstimationMinBounces( ) );
        ImGui::SetNextItemWidth( 100.0F );
        if ( ImGui::InputInt( "Next Event Estimation", &neeMinBounces ) )
        {
          _renderer->settings( ).setNextEventEstimationMinBounces( static_cast<uint32_t>( neeMinBounces ) );
          _renderer->settings( ).setAccumulatingFrames( false );
        }

        static int perPixelSampleRate = static_cast<int>( _renderer->settings( ).getPerPixelSampleRate( ) );
        ImGui::SetNextItemWidth( 129.0F );
        if ( ImGui::InputInt( "Per pixel sample rate", &perPixelSampleRate ) )
        {
          _renderer->settings( ).setPerPixelSampleRate( perPixelSampleRate );
          _renderer->settings( ).setAccumulatingFrames( false );
        }

        static int depth = static_cast<int>( _renderer->settings( ).getPathDepth( ) );
        ImGui::SetNextItemWidth( 129.0F );
        if ( ImGui::InputInt( "Path depth", &depth ) )
        {
          _renderer->settings( ).setPathDepth( static_cast<uint32_t>( depth ) );
          _renderer->settings( ).setAccumulatingFrames( false );
        }

        if ( ImGui::Button( "Recompile shaders" ) )
        {
          _renderer->settings( ).triggerPipelineRefresh( );
        }

        ImGui::NewLine( );
      }

      if ( ImGui::CollapsingHeader( "Scenes", flags ) )
      {
        if ( ImGui::Button( "Cornell" ) )
        {
          loadScene( _renderer, Level::eCornell );
        }

        ImGui::SameLine( );

        if ( ImGui::Button( "Animations" ) )
        {
          loadScene( _renderer, Level::eAnimations );
        }

        ImGui::SameLine( );

        if ( ImGui::Button( "Spheres" ) )
        {
          loadScene( _renderer, Level::eSpheres );
        }

        ImGui::SameLine( );

        if ( ImGui::Button( "Mirrors" ) )
        {
          loadScene( _renderer, Level::eMirrors );
        }

        ImGui::SameLine( );

        if ( ImGui::Button( "Sponza" ) )
        {
          loadScene( _renderer, Level::eSponza );
        }

        ImGui::NewLine( );
      }

      if ( ImGui::CollapsingHeader( "Camera", flags ) )
      {
        static float aperture = static_cast<int>( _renderer->scene( ).getCamera( )->getAperture( ) );
        if ( ImGui::SliderFloat( "Aperture", &aperture, 0.0F, 2.0F ) )
        {
          _renderer->scene( ).getCamera( )->setAperture( aperture );
          _renderer->settings( ).setAccumulatingFrames( false );
        }

        static float focalDistance = static_cast<int>( _renderer->scene( ).getCamera( )->getFocalDistance( ) );
        if ( ImGui::SliderFloat( "Focal Point", &focalDistance, 0.0F, 20.0F ) )
        {
          _renderer->scene( ).getCamera( )->setFocalDistance( focalDistance );
          _renderer->settings( ).setAccumulatingFrames( false );
        }

        static float fov = static_cast<int>( _renderer->scene( ).getCamera( )->getFov( ) );
        if ( ImGui::SliderFloat( "Field of View", &fov, 10.0F, 150.0F ) )
        {
          _renderer->scene( ).getCamera( )->setFov( fov );
          _renderer->settings( ).setAccumulatingFrames( false );
        }

        //ImGui::Separator( );
        //ImGui::Text( "Cam Pos:   " );
        //ImGui::SameLine( );
        //ImGui::Text( glm::to_string( _renderer->scene( ).getCamera( )->getPosition( ) ).c_str( ) );
        //
        //ImGui::Text( "Cam Front: " );
        //ImGui::SameLine( );
        //ImGui::Text( glm::to_string( _renderer->scene( ).getCamera( )->getFront( ) ).c_str( ) );
      }
    }
    ImGui::End( );
  }

private:
  rx::Rayex* _renderer;
};

#endif // CUSTOM_GUI_HPP
