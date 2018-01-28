//
// Created by terde on 22.02.2017.
//

#include "stdafx.h"
#include "MainSceneResourceLoader.h"
#include "TextureResource.h"

void MainSceneResourceLoader::Load() {
    resource_manager->Add<FontResource>("arial.ttf", "font", "./Resources/");
    resource_manager->Add<TextureResource>("logo.jpg", "logo", "./Resources/");
}