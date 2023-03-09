/*
 * $Id: FormComponent.java 471754 2006-11-06 14:55:09Z husted $
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

package org.apache.struts.faces.component;


import java.util.Map;
import javax.faces.component.UIForm;
import javax.faces.context.FacesContext;
import javax.faces.el.ValueBinding;
import javax.servlet.http.HttpSession;
import org.apache.commons.beanutils.DynaBean;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.apache.struts.Globals;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionServlet;
import org.apache.struts.action.DynaActionFormClass;
import org.apache.struts.config.ActionConfig;
import org.apache.struts.config.FormBeanConfig;
import org.apache.struts.config.ModuleConfig;
import org.apache.struts.util.RequestUtils;


/**
 * <p><strong>FormComponent</strong> is a specialized subclass of
 * <code>javax.faces.component.UIForm</code> that supports automatic
 * creation of form beans in request or session scope.</p>
 *
 * @version $Rev: 471754 $ $Date: 2006-11-06 08:55:09 -0600 (Mon, 06 Nov 2006) $
 */
public class FormComponent extends UIForm {


    // -------------------------------------------------------- Static Variables


    /**
     * <p>The <code>Log</code> instance for this class.</p>
     */
    protected static Log log = LogFactory.getLog(FormComponent.class);


    // ------------------------------------------------------ Instance Variables


    private String action = null;
    private String enctype = null;
    private String focus = null;
    private String focusIndex = null;
    private String onreset = null;
    private String onsubmit = null;
    private String style = null;
    private String styleClass = null;
    private String target = null;


    // ---------------------------------------------------- Component Properties


    /**
     * <p>Return the Struts action path to which this form should be submitted.
     * </p>
     */
    public String getAction() {

        if (this.action != null) {
            return (this.action);
        }
        ValueBinding vb = getValueBinding("action");
        if (vb != null) {
            return ((String) vb.getValue(getFacesContext()));
        } else {
            return (null);
        }

    }


    /**
     * <p>Set the Struts action to which this form should be submitted.</p>
     *
     * @param action The new action path
     */
    public void setAction(String action) {

        this.action = action;

    }


    /**
     * <p>Return the encoding type for this form submit.</p>
     */
    public String getEnctype() {

        if (this.enctype != null) {
            return (this.enctype);
        }
        ValueBinding vb = getValueBinding("enctype");
        if (vb != null) {
            return ((String) vb.getValue(getFacesContext()));
        } else {
            return (null);
        }

    }


    /**
     * <p>Set the encoding type for this form submit.</p>
     *
     * @param enctype The new enctype path
     */
    public void setEnctype(String enctype) {

        this.enctype = enctype;

    }


    /**
     * <p>Return the component family to which this component belongs.</p>
     */
    public String getFamily() {

        return "org.apache.struts.faces.Form";

    }


    /**
     * <p>Return the focus element name.</p>
     */
    public String getFocus() {

        if (this.focus != null) {
            return (this.focus);
        }
        ValueBinding vb = getValueBinding("focus");
        if (vb != null) {
            return ((String) vb.getValue(getFacesContext()));
        } else {
            return (null);
        }

    }


    /**
     * <p>Set the focus element name.</p>
     *
     * @param focus The new focus path
     */
    public void setFocus(String focus) {

        this.focus = focus;

    }


    /**
     * <p>Return the focus element index.</p>
     */
    public String getFocusIndex() {

        if (this.focusIndex != null) {
            return (this.focusIndex);
        }
        ValueBinding vb = getValueBinding("focusIndex");
        if (vb != null) {
            return ((String) vb.getValue(getFacesContext()));
        } else {
            return (null);
        }

    }


    /**
     * <p>Set the focus element index.</p>
     *
     * @param focusIndex The new focusIndex path
     */
    public void setFocusIndex(String focusIndex) {

        this.focusIndex = focusIndex;

    }


    /**
     * <p>Return the JavaScript to execute on form reset.</p>
     */
    public String getOnreset() {

        if (this.onreset != null) {
            return (this.onreset);
        }
        ValueBinding vb = getValueBinding("onreset");
        if (vb != null) {
            return ((String) vb.getValue(getFacesContext()));
        } else {
            return (null);
        }

    }


    /**
     * <p>Set the JavaScript to execute on form reset.</p>
     *
     * @param onreset The new onreset path
     */
    public void setOnreset(String onreset) {

        this.onreset = onreset;

    }


    /**
     * <p>Return the JavaScript to execute on form submit.</p>
     */
    public String getOnsubmit() {

        if (this.onsubmit != null) {
            return (this.onsubmit);
        }
        ValueBinding vb = getValueBinding("onsubmit");
        if (vb != null) {
            return ((String) vb.getValue(getFacesContext()));
        } else {
            return (null);
        }

    }


    /**
     * <p>Set the JavaScript to execute on form submit.</p>
     *
     * @param onsubmit The new onsubmit path
     */
    public void setOnsubmit(String onsubmit) {

        this.onsubmit = onsubmit;

    }


    /**
     * <p>Return the CSS style(s) to be rendered for this component.</p>
     */
    public String getStyle() {

        ValueBinding vb = getValueBinding("style");
        if (vb != null) {
            return (String) vb.getValue(getFacesContext());
        } else {
            return style;
        }

    }


    /**
     * <p>Set the CSS style(s) to be rendered for this component.</p>
     *
     * @param style The new CSS style(s)
     */
    public void setStyle(String style) {

        this.style = style;

    }


    /**
     * <p>Return the CSS style class(es) to be rendered for this component.</p>
     */
    public String getStyleClass() {

        ValueBinding vb = getValueBinding("styleClass");
        if (vb != null) {
            return (String) vb.getValue(getFacesContext());
        } else {
            return styleClass;
        }

    }


    /**
     * <p>Set the CSS style class(es) to be rendered for this component.</p>
     *
     * @param styleClass The new CSS style class(es)
     */
    public void setStyleClass(String styleClass) {

        this.styleClass = styleClass;

    }


    /**
     * <p>Return the target frame for the response to this form submit.</p>
     */
    public String getTarget() {

        ValueBinding vb = getValueBinding("target");
        if (vb != null) {
            return (String) vb.getValue(getFacesContext());
        } else {
            return target;
        }

    }


    /**
     * <p>Set the target frame for the response to this form submit.</p>
     *
     * @param target The new CSS target(s)
     */
    public void setTarget(String target) {

        this.target = target;

    }


    // ---------------------------------------------------------- UIForm Methods


    /**
     * <p>Create an instance of the form bean (if necessary) before
     * delegating to the standard decoding process.</p>
     *
     * @param context FacesContext for the request we are processing
     */
    public void processDecodes(FacesContext context) {

        if (context == null) {
            throw new NullPointerException();
        }

        if (log.isDebugEnabled()) {
            log.debug("processDecodes(" + getClientId(context) + ")");
        }

        // Create the form bean (if necessary)
        Map params = context.getExternalContext().getRequestParameterMap();
        if (params.containsKey(getClientId(context))) {
            createActionForm(context);
        }

        // Perform the standard decode processing
        super.processDecodes(context);

    }


    /**
     * <p>Restore our state from the specified object.</p>
     *
     * @param context <code>FacesContext</code> for the current request
     * @param state Object containing our saved state
     */
    public void restoreState(FacesContext context, Object state) {

        Object values[] = (Object[]) state;
        super.restoreState(context, values[0]);
        action = (String) values[1];
        enctype = (String) values[2];
        focus = (String) values[3];
        focusIndex = (String) values[4];
        onreset = (String) values[5];
        onsubmit = (String) values[6];
        style = (String) values[7];
        styleClass = (String) values[8];
        target = (String) values[9];

    }


    /**
     * <p>Create and return an object representing our state to be saved.</p>
     *
     * @param context <code>FacesContext</code> for the current request
     */
    public Object saveState(FacesContext context) {

        Object values[] = new Object[10];
        values[0] = super.saveState(context);
        values[1] = action;
        values[2] = enctype;
        values[3] = focus;
        values[4] = focusIndex;
        values[5] = onreset;
        values[6] = onsubmit;
        values[7] = style;
        values[8] = styleClass;
        values[9] = target;
        return (values);

    }



    // ---------------------------------------------------------- Public Methods


    /**
     * <p>Create an appropriate form bean in the appropriate scope, if one
     * does not already exist.</p>
     *
     * @param context FacesContext for the current request
     *
     * @exception IllegalArgumentException if no ActionConfig for the
     *  specified action attribute can be located
     * @exception IllegalArgumentException if no FormBeanConfig for the
     *  specified form bean can be located
     * @exception IllegalArgumentException if no ModuleConfig can be
     *  located for this application module
     */
    public void createActionForm(FacesContext context) {

        // Look up the application module configuration information we need
        ModuleConfig moduleConfig = lookupModuleConfig(context);

        // Look up the ActionConfig we are processing
        String action = getAction();
        ActionConfig actionConfig = moduleConfig.findActionConfig(action);
        if (actionConfig == null) {
            throw new IllegalArgumentException("Cannot find action '" +
                                               action + "' configuration");
        }

        // Does this ActionConfig specify a form bean?
        String name = actionConfig.getName();
        if (name == null) {
            return;
        }

        // Look up the FormBeanConfig we are processing
        FormBeanConfig fbConfig = moduleConfig.findFormBeanConfig(name);
        if (fbConfig == null) {
            throw new IllegalArgumentException("Cannot find form bean '" +
                                               name + "' configuration");
        }

        // Does a usable form bean attribute already exist?
        String attribute = actionConfig.getAttribute();
        String scope = actionConfig.getScope();
        ActionForm instance = null;
        if ("request".equals(scope)) {
            instance = (ActionForm)
                context.getExternalContext().getRequestMap().get(attribute);
        } else if ("session".equals(scope)) {
            HttpSession session = (HttpSession)
                context.getExternalContext().getSession(true);
            instance = (ActionForm)
                context.getExternalContext().getSessionMap().get(attribute);
        }
        if (instance != null) {
            if (fbConfig.getDynamic()) {
                String className =
                    ((DynaBean) instance).getDynaClass().getName();
                if (className.equals(fbConfig.getName())) {
                    if (log.isDebugEnabled()) {
                        log.debug
                            (" Recycling existing DynaActionForm instance " +
                             "of type '" + className + "'");
                    }
                    return;
                }
            } else {
                try {
                    Class configClass =
                        RequestUtils.applicationClass(fbConfig.getType());
                    if (configClass.isAssignableFrom(instance.getClass())) {
                        if (log.isDebugEnabled()) {
                            log.debug
                                (" Recycling existing ActionForm instance " +
                                 "of class '" + instance.getClass().getName()
                                 + "'");
                        }
                        return;
                    }
                } catch (Throwable t) {
                    throw new IllegalArgumentException
                        ("Cannot load form bean class '" +
                         fbConfig.getType() + "'");
                }
            }
        }

        // Create a new form bean instance
        if (fbConfig.getDynamic()) {
            try {
                DynaActionFormClass dynaClass =
                    DynaActionFormClass.createDynaActionFormClass(fbConfig);
                instance = (ActionForm) dynaClass.newInstance();
                if (log.isDebugEnabled()) {
                    log.debug
                        (" Creating new DynaActionForm instance " +
                         "of type '" + fbConfig.getType() + "'");
                    log.trace(" --> " + instance);
                }
            } catch (Throwable t) {
                throw new IllegalArgumentException
                    ("Cannot create form bean of type '" +
                     fbConfig.getType() + "'");
            }
        } else {
            try {
                instance = (ActionForm)
                    RequestUtils.applicationInstance(fbConfig.getType());
                if (log.isDebugEnabled()) {
                    log.debug
                        (" Creating new ActionForm instance " +
                         "of type '" + fbConfig.getType() + "'");
                    log.trace(" --> " + instance);
                }
            } catch (Throwable t) {
                throw new IllegalArgumentException
                    ("Cannot create form bean of class '" +
                     fbConfig.getType() + "'");
            }
        }

        // Configure and cache the form bean instance in the correct scope
        ActionServlet servlet = (ActionServlet)
            context.getExternalContext().getApplicationMap().get
            (Globals.ACTION_SERVLET_KEY);
        instance.setServlet(servlet);
        if ("request".equals(scope)) {
            context.getExternalContext().getRequestMap().put
                (attribute, instance);
        } else if ("session".equals(scope)) {
            context.getExternalContext().getSessionMap().put
                (attribute, instance);
        }

    }


    /**
     * <p>Return the <code>ModuleConfig</code> for the application module
     * this form is being processed for.</p>
     *
     * @param context The <code>FacesContext</code> for the current request
     *
     * @exception IllegalArgumentException if no <code>ModuleConfig</code>
     *  can be found
     */
    public ModuleConfig lookupModuleConfig(FacesContext context) {

        // Look up the application module configuration information we need
        ModuleConfig modConfig = (ModuleConfig)
            context.getExternalContext().getRequestMap().get
            (Globals.MODULE_KEY);
        if (modConfig == null) {
            modConfig = (ModuleConfig)
                context.getExternalContext().getApplicationMap().get
                (Globals.MODULE_KEY);
        }
        if (modConfig == null) {
            throw new IllegalArgumentException
                ("Cannot find module configuration");
        }
        return (modConfig);

    }


}
