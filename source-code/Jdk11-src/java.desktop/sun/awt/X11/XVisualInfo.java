// This file is an automatically generated file, please do not edit this file, modify the WrapperGenerator.java file instead !

package sun.awt.X11;

import jdk.internal.misc.Unsafe;

import sun.util.logging.PlatformLogger;
public class XVisualInfo extends XWrapperBase { 
	private Unsafe unsafe = XlibWrapper.unsafe; 
	private final boolean should_free_memory;
	public static int getSize() { return 64; }
	public int getDataSize() { return getSize(); }

	long pData;

	public long getPData() { return pData; }


	public XVisualInfo(long addr) {
		log.finest("Creating");
		pData=addr;
		should_free_memory = false;
	}


	public XVisualInfo() {
		log.finest("Creating");
		pData = unsafe.allocateMemory(getSize());
		should_free_memory = true;
	}


	public void dispose() {
		log.finest("Disposing");
		if (should_free_memory) {
			log.finest("freeing memory");
			unsafe.freeMemory(pData); 
	}
		}
	public long get_visual(int index) { log.finest(""); return Native.getLong(pData+0)+index*Native.getLongSize(); }
	public long get_visual() { log.finest("");return Native.getLong(pData+0); }
	public void set_visual(long v) { log.finest(""); Native.putLong(pData + 0, v); }
	public long get_visualid() { log.finest("");return (Native.getLong(pData+8)); }
	public void set_visualid(long v) { log.finest(""); Native.putLong(pData+8, v); }
	public int get_screen() { log.finest("");return (Native.getInt(pData+16)); }
	public void set_screen(int v) { log.finest(""); Native.putInt(pData+16, v); }
	public int get_depth() { log.finest("");return (Native.getInt(pData+20)); }
	public void set_depth(int v) { log.finest(""); Native.putInt(pData+20, v); }
	public int get_class() { log.finest("");return (Native.getInt(pData+24)); }
	public void set_class(int v) { log.finest(""); Native.putInt(pData+24, v); }
	public long get_red_mask() { log.finest("");return (Native.getLong(pData+32)); }
	public void set_red_mask(long v) { log.finest(""); Native.putLong(pData+32, v); }
	public long get_green_mask() { log.finest("");return (Native.getLong(pData+40)); }
	public void set_green_mask(long v) { log.finest(""); Native.putLong(pData+40, v); }
	public long get_blue_mask() { log.finest("");return (Native.getLong(pData+48)); }
	public void set_blue_mask(long v) { log.finest(""); Native.putLong(pData+48, v); }
	public int get_colormap_size() { log.finest("");return (Native.getInt(pData+56)); }
	public void set_colormap_size(int v) { log.finest(""); Native.putInt(pData+56, v); }
	public int get_bits_per_rgb() { log.finest("");return (Native.getInt(pData+60)); }
	public void set_bits_per_rgb(int v) { log.finest(""); Native.putInt(pData+60, v); }


	String getName() {
		return "XVisualInfo"; 
	}


	String getFieldsAsString() {
		StringBuilder ret = new StringBuilder(400);

		ret.append("visual = ").append( get_visual() ).append(", ");
		ret.append("visualid = ").append( get_visualid() ).append(", ");
		ret.append("screen = ").append( get_screen() ).append(", ");
		ret.append("depth = ").append( get_depth() ).append(", ");
		ret.append("class = ").append( get_class() ).append(", ");
		ret.append("red_mask = ").append( get_red_mask() ).append(", ");
		ret.append("green_mask = ").append( get_green_mask() ).append(", ");
		ret.append("blue_mask = ").append( get_blue_mask() ).append(", ");
		ret.append("colormap_size = ").append( get_colormap_size() ).append(", ");
		ret.append("bits_per_rgb = ").append( get_bits_per_rgb() ).append(", ");
		return ret.toString();
	}


}



