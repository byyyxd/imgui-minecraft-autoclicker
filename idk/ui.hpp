// wszz#2021 | darkin.xyz

#pragma once
#include "includes.hpp"
#include "xorstr.hpp"
#include "bind.hpp"
#include "config.hpp"

namespace ui
{
	namespace text
	{
		int change( int num )
		{
			switch ( num )
			{
				case 1:
					for ( int i = 0; i < 3; i++ )
					{
						cfg::utils::rgb[ i ] = cfg::utils::orange[ i ];
						cfg::utils::rgb_2[ i ] = 252;
					}
					return cfg::utils::switchTab = 1;
					break;
				case 2:
					for ( int i = 0; i < 3; i++ )
					{
						cfg::utils::rgb_2[ i ] = cfg::utils::orange[ i ];
						cfg::utils::rgb[ i ] = 252;
					}
					return cfg::utils::switchTab = 2;
					break;
			}
		}
	}

	void tab_1( ImFont *icons )
	{
		ImGui::PushStyleColor( ImGuiCol_Border, ImColor( 63, 63, 63 ) );
		ImGui::SetNextWindowPos( ImVec2( 0, 0 ) );
		ImGui::BeginChild( xorstr( "##header" ), ImVec2( 80, 450 ), true, ImGuiWindowFlags_NoScrollbar );
		{
			ImGui::PushFont( icons );
			ImGui::SpacingInt( 35 );
			ImGui::SameLine( 18.f );

			ImGui::PushStyleColor( ImGuiCol_Text, ImColor( cfg::utils::rgb[ 0 ], cfg::utils::rgb[ 1 ], cfg::utils::rgb[ 2 ] ) );
			ImGui::Text( xorstr( "G" ) );
			if ( ImGui::IsItemClicked( ) )
				text::change( 1 );
			ImGui::PopStyleColor( );

			ImGui::SpacingInt( 25 );
			ImGui::SameLine( 18.f );

			ImGui::PushStyleColor( ImGuiCol_Text, ImColor( cfg::utils::rgb_2[ 0 ], cfg::utils::rgb_2[ 1 ], cfg::utils::rgb_2[ 2 ] ) );
			ImGui::Text( xorstr( "Q" ) );
			if ( ImGui::IsItemClicked( ) )
				text::change( 2 );
			ImGui::PopStyleColor( );

			ImGui::PopFont( );
		}
		ImGui::PopStyleColor( );
		ImGui::EndChild( );
	}

	namespace ac
	{
		void tab_2( ImFont *font )
		{
			ImGui::SetNextWindowPos( ImVec2( 90, 30 ) );
			ImGui::PushStyleColor( ImGuiCol_Border, ImColor( 63, 63, 63 ) );
			ImGui::PushStyleColor( ImGuiCol_CheckMark, ImColor( 70, 0, 255 ) );
			ImGui::PushStyleColor( ImGuiCol_SliderGrab, ImColor( 70, 0, 255 ) );
			ImGui::PushStyleColor( ImGuiCol_SliderGrabActive, ImColor( 108, 0, 255 ) );
			ImGui::BeginChild( xorstr( "##tab2" ), ImVec2( 350, 250 ), true, ImGuiWindowFlags_NoScrollbar );
			{
				ImGui::SpacingInt( 5 );
				ImGui::SameLine( 15.f );
				ImGui::TextColored( ImColor( 63, 63, 63 ), xorstr( "Auto Click" ) );
				ImGui::SpacingInt( 10 );
				ImGui::Checkbox( xorstr( " enabled" ), &cfg::ac::enabled );
				ImGui::SameLine( 90.f );
				keybind::key_bind( cfg::ac::acbind, 150, 20 );
				if ( ImGui::IsItemHovered( ) )
					ImGui::SetTooltip( xorstr( "Do a keybind to toggle on and off." ) );
				ImGui::SpacingInt( 5 );
				ImGui::Checkbox( xorstr( " right click" ), &cfg::ac::rightenabled );
				ImGui::SpacingInt( 5 );
				ImGui::Checkbox( xorstr( " only minecraft" ), &cfg::ac::onlymc );
				ImGui::SpacingInt( 5 );
				ImGui::PushItemWidth( 150.f );
				ImGui::InputText( xorstr( "##window" ), cfg::ac::windowname, IM_ARRAYSIZE( cfg::ac::windowname ) );
				if ( ImGui::IsItemHovered( ) )
					ImGui::SetTooltip( xorstr( "Put your minecraft window name.\n\nExample: Lunar" ) );
				ImGui::SpacingInt( 5 );
				ImGui::PushItemWidth( 150.f );
				ImGui::SliderInt( xorstr( "##max" ), &cfg::ac::max_cps, 1.0f, 20.0f, xorstr( "Max %.1f" ) );
				ImGui::SpacingInt( 5 );
				ImGui::PushItemWidth( 150.f );
				ImGui::SliderInt( xorstr( "##min" ), &cfg::ac::min_cps, 1.0f, 20.0f, xorstr( "Min %.1f" ) );
			}
			ImGui::PopStyleColor( 4 );
			ImGui::EndChild( );
		}
	}

	void tab_3( ImFont *font )
	{

	}

}