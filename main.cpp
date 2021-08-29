#include "CustomCamera.hpp"
#include "CustomGui.hpp"
#include "CustomWindow.hpp"

#include <filesystem>

int main( )
{
  // Window dimensions.
  const int width  = 1920;
  const int height = 1080;

  //std::filesystem::copy( PATH_TO_ASSETS "shaders", PATH_TO_EXECUTABLE "shaders", std::filesystem::copy_options::overwrite_existing | std::filesystem::copy_options::recursive );
  std::filesystem::copy( PATH_TO_ASSETS "models", PATH_TO_EXECUTABLE "models", std::filesystem::copy_options::overwrite_existing | std::filesystem::copy_options::recursive );
  std::filesystem::copy( PATH_TO_ASSETS "DroidSans.ttf", PATH_TO_EXECUTABLE "DroidSans.ttf", std::filesystem::copy_options::overwrite_existing | std::filesystem::copy_options::recursive );

  rx::Rayex renderer;

  renderer.settings( ).setShadersPath( PATH_TO_RAYEX_SHADERS );

  //renderer.settings( ).setAssetsPath( PATH_TO_ASSETS );

  // Custom camera
  renderer.scene( ).setCamera( std::make_shared<CustomCamera>(
    width, height, glm::vec3( 0.0F, 0.0F, 3.0F ) ) );

  // Custom window
  renderer.setWindow( std::make_shared<CustomWindow>(
    width, height, "Rayex Example", SDL_WINDOW_RESIZABLE, &renderer.scene( ) ) );

  // Custom ImGui based Gui
  renderer.setGui( std::make_shared<CustomGui>( &renderer ) );

  // ... and initialize the renderer.
  renderer.init( );

  loadScene( &renderer, Level::eSpheres );

  while ( renderer.isRunning( ) )
  {
    updateScene( &renderer );

    renderer.run( );
  }

  return 0;
}
