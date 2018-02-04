//
// Created by terde on 22.02.2017.
//

#include "stdafx.h"
#include "main-scene-resource-loader.h"
#include "texture-resource.h"

void MainSceneResourceLoader::Load() {
    resource_manager->Add<FontResource>("arial.ttf", "font", "./Resources/");
    resource_manager->Add<TextureResource>("logo.jpg", "logo", "./Resources/");
}