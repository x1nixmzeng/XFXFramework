/********************************************************
 *	Texture.h											*
 *														*
 *	XFX Texture definition file							*
 *	Copyright � XFX Team. All Rights Reserved			*
 ********************************************************/
#ifndef _XFX_GRAPHICS_TEXTURE_
#define _XFX_GRAPHICS_TEXTURE_

#include <System/Types.h>
#include <System/IO/Stream.h>
#include "GraphicsResource.h"

using namespace System;
using namespace System::IO;

namespace XFX
{
	namespace Graphics
	{
		struct TextureCreationParameters;
		struct TextureInformation;

		// Represents a texture resource.
		class Texture : public GraphicsResource, virtual Object
		{
		private:
			static ImageFileFormat_t ILimageformat2XNAimageformat(int ILFormat);
			int _levelCount;
			
		protected:
			virtual void Dispose(bool disposing);
		
		public:
			int LevelCount();
			int LevelOfDetail;

			Texture();
			~Texture();
			
			static Texture* FromFile(GraphicsDevice* graphicsDevice, Stream* textureStream);
			static Texture* FromFile(GraphicsDevice* graphicsDevice, char* filename);
			static Texture* FromFile(GraphicsDevice* graphicsDevice, Stream* textureStream, int numberBytes);
			static Texture* FromFile(GraphicsDevice* graphicsDevice, Stream* textureStream, TextureCreationParameters creationParameters);
			static Texture* FromFile(GraphicsDevice* graphicsDevice, char* filename, TextureCreationParameters creationParameters);
			static Texture* FromFile(GraphicsDevice* graphicsDevice, Stream* textureStream, int numberBytes, TextureCreationParameters creationParameters);
			static Texture* FromFile(GraphicsDevice* graphicsDevice, char* filename, int width, int height, int depth);
			
			void GenerateMipMaps(TextureFilter_t filterType);
			static TextureCreationParameters GetCreationParameters(GraphicsDevice* graphicsDevice, Stream* textureStream);
			static TextureCreationParameters GetCreationParameters(GraphicsDevice* graphicsDevice, char* filename);
			static TextureCreationParameters GetCreationParameters(GraphicsDevice* graphicsDevice, Stream* textureStream, int numberBytes);
			static TextureInformation GetTextureInformation(Stream* textureStream);
			static TextureInformation GetTextureInformation(char* filename);
			static TextureInformation GetTextureInformation(Stream* textureStream, int numberBytes);
			void Save(char* filename, ImageFileFormat_t format);
		};
	}
}

#endif //_XFX_GRAPHICS_TEXTURE_
