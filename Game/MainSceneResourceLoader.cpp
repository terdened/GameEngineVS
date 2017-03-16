//
// Created by terde on 22.02.2017.
//

#include "stdafx.h"
#include "MainSceneResourceLoader.h"
#include "TextureResource.h"

void MainSceneResourceLoader::Load() {
    resourceManager->Add<FontResource>("arial.ttf", "font", "./Resources/");
    resourceManager->Add<TextureResource>("logo.jpg", "logo", "./Resources/");
}